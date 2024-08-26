import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.security.*;
import java.security.spec.X509EncodedKeySpec;
import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import javax.swing.*;
import java.util.Base64;

public class Client extends Frame {
    private TextArea textArea = new TextArea();
    private TextField textField = new TextField();
    private Button sendButton = new Button("Send");
    private Choice modeChoice = new Choice();
    private Button sendFileButton = new Button("Send File");
    private PrintWriter out;
    private BufferedReader in;
    private Cipher cipherAES;
    private SecretKey aesKey;
    private String username;

    public static void main(String[] args) {
        new Client();
    }

    public Client() {
        super("Chat Application");
        setupUI();
        String usernameInput = getUsernameFromDialog();
        if (usernameInput != null && !usernameInput.trim().isEmpty()) {
            username = usernameInput.trim();
            connect();
        } else {
            System.exit(0);
        }
    }

    private void setupUI() {
        this.setLayout(new BorderLayout());
        this.add(textArea, BorderLayout.CENTER);
        Panel p = new Panel();
        p.setLayout(new BorderLayout());
        p.add(textField, BorderLayout.CENTER);
        p.add(sendButton, BorderLayout.EAST);
        p.add(modeChoice, BorderLayout.NORTH);
        p.add(sendFileButton, BorderLayout.WEST);

        modeChoice.add("Confidentiality");
        modeChoice.add("Integrity");
        modeChoice.select("Confidentiality");

        this.add(p, BorderLayout.SOUTH);

        sendButton.addActionListener(e -> {
            sendMessage(textField.getText());
            textField.setText("");
        });

        textField.addActionListener(e -> {
            sendMessage(textField.getText());
            textField.setText("");
        });

        sendFileButton.addActionListener(e -> {
            FileDialog fileDialog = new FileDialog(this, "Choose a file", FileDialog.LOAD);
            fileDialog.setVisible(true);
            if (fileDialog.getFile() != null) {
                sendFile(fileDialog.getDirectory() + fileDialog.getFile());
            }
        });

        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        this.setSize(500, 400);
        this.setVisible(true);
    }

    private String getUsernameFromDialog() {
        return JOptionPane.showInputDialog(
            this,
            "Enter your username:",
            "Username",
            JOptionPane.PLAIN_MESSAGE
        );
    }

    private void connect() {
        String hostName = "localhost";
        int port = 1234;

        try {
            Socket socket = new Socket(hostName, port);
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            PublicKey publicKey = loadPublicKey("./public_key.pem");
            textArea.append("Public key loaded.\n");

            KeyGenerator keyGen = KeyGenerator.getInstance("AES");
            keyGen.init(256);
            aesKey = keyGen.generateKey();

            Cipher cipherRSA = Cipher.getInstance("RSA/ECB/PKCS1Padding");
            cipherRSA.init(Cipher.ENCRYPT_MODE, publicKey);
            byte[] encryptedAesKey = cipherRSA.doFinal(aesKey.getEncoded());
            String encodedKey = Base64.getEncoder().encodeToString(encryptedAesKey);
            out.println(encodedKey);

            cipherAES = Cipher.getInstance("AES/CBC/PKCS5Padding");
            cipherAES.init(Cipher.ENCRYPT_MODE, aesKey, new IvParameterSpec(new byte[16]));

            new Thread(() -> {
                try {
                    String line;
                    while ((line = in.readLine()) != null) {
                        textArea.append(line + "\n");
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }).start();
        } catch (Exception e) {
            System.err.println("Client exception: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private void sendMessage(String message) {
        try {
            byte[] messageBytes = (username + ": " + message).getBytes(StandardCharsets.UTF_8);
    
            // Compute the hash of the message
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(messageBytes);
    
            // Append hash to message
            byte[] messageAndHash = new byte[messageBytes.length + hash.length];
            System.arraycopy(messageBytes, 0, messageAndHash, 0, messageBytes.length);
            System.arraycopy(hash, 0, messageAndHash, messageBytes.length, hash.length);
    
            // Encrypt message and hash
            cipherAES.init(Cipher.ENCRYPT_MODE, aesKey); // Ensure a new IV for each message
            byte[] iv = cipherAES.getIV();
            byte[] encryptedMessageAndHash = cipherAES.doFinal(messageAndHash);
    
            String encodedIV = Base64.getEncoder().encodeToString(iv);
            String encodedMessage = Base64.getEncoder().encodeToString(encryptedMessageAndHash);
            String header = modeChoice.getSelectedItem() + ":text:" + encodedIV + ":" + encodedMessage;
            out.println(header);
        } catch (Exception e) {
            System.err.println("Error sending encrypted message: " + e.getMessage());
            e.printStackTrace();
        }
    }    
    
    private void sendFile(String filePath) {
        File file = new File(filePath);
        String extension = "";
        int i = filePath.lastIndexOf('.');
        if (i > 0) {
            extension = filePath.substring(i);
        }
        try (FileInputStream fis = new FileInputStream(file)) {
            byte[] fileBytes = new byte[(int) file.length()];
            fis.read(fileBytes);
    
            // Compute the hash of the file
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(fileBytes);
    
            // Append hash to file data
            byte[] fileDataAndHash = new byte[fileBytes.length + hash.length];
            System.arraycopy(fileBytes, 0, fileDataAndHash, 0, fileBytes.length);
            System.arraycopy(hash, 0, fileDataAndHash, fileBytes.length, hash.length);
    
            // Encrypt file data and hash
            cipherAES.init(Cipher.ENCRYPT_MODE, aesKey);  // Ensure a new IV for each message
            byte[] iv = cipherAES.getIV();
            byte[] encryptedFileDataAndHash = cipherAES.doFinal(fileDataAndHash);
    
            String encodedIV = Base64.getEncoder().encodeToString(iv);
            String encodedFile = Base64.getEncoder().encodeToString(encryptedFileDataAndHash);
            String header = "Integrity:file:" + encodedIV + ":" + encodedFile + ":" + extension;
            out.println(header);
        } catch (Exception e) {
            System.err.println("Error sending file: " + e.getMessage());
            e.printStackTrace();
        }
    }    
    

    private static PublicKey loadPublicKey(String filePath) throws Exception {
        String publicKeyPEM = new String(Files.readAllBytes(Paths.get(filePath)));
        publicKeyPEM = publicKeyPEM.replace("-----BEGIN PUBLIC KEY-----", "").replace("-----END PUBLIC KEY-----", "");
        publicKeyPEM = publicKeyPEM.replaceAll("\\s", "");
        byte[] encoded = Base64.getDecoder().decode(publicKeyPEM);
        X509EncodedKeySpec keySpec = new X509EncodedKeySpec(encoded);
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        return keyFactory.generatePublic(keySpec);
    }
}
