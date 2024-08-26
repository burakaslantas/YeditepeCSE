import java.awt.FileDialog;
import java.awt.Frame;
import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.security.*;
import java.security.spec.PKCS8EncodedKeySpec;
import java.util.*;
import java.util.concurrent.*;
import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class Server {
    private static final int port = 1234;
    private static ConcurrentHashMap<String, ClientHandler> clients = new ConcurrentHashMap<>();
    private static PrivateKey privateKey;

    public static void main(String[] args) throws Exception {
        System.out.println("Server: Private key loaded.");
        ExecutorService executor = Executors.newFixedThreadPool(10);
        privateKey = loadPrivateKey("./private_key.pem");

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server is listening on port " + port);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                ClientHandler handler = new ClientHandler(clientSocket);
                executor.submit(handler);
            }
        } catch (IOException e) {
            System.out.println("Server exception: " + e.getMessage());
        }
    }

    public static void broadcastMessage(String message, String senderId) {
        clients.forEach((id, client) -> {
            if (!id.equals(senderId)) {
                client.sendMessage(message);
            }
        });
    }

    private static class ClientHandler implements Runnable {
        private Socket clientSocket;
        private PrintWriter out;
        private String clientId;
        private Cipher cipherAES;
    
        public ClientHandler(Socket socket) {
            this.clientSocket = socket;
            this.clientId = clientSocket.getRemoteSocketAddress().toString(); // Using the socket address as ID for simplicity
            clients.put(clientId, this);
        }
    
        public void sendMessage(String message) {
            out.println(message);
        }
    
        @Override
        public void run() {
            try {
                InputStream input = clientSocket.getInputStream();
                OutputStream output = clientSocket.getOutputStream();
                BufferedReader reader = new BufferedReader(new InputStreamReader(input));
                out = new PrintWriter(output, true);
    
                Cipher cipherRSA = Cipher.getInstance("RSA/ECB/PKCS1Padding");
                cipherRSA.init(Cipher.DECRYPT_MODE, privateKey);
                String encryptedKey = reader.readLine();
                byte[] decodedKey = Base64.getDecoder().decode(encryptedKey);
                byte[] aesKeyBytes = cipherRSA.doFinal(decodedKey);
                SecretKey aesKey = new SecretKeySpec(aesKeyBytes, "AES");
                cipherAES = Cipher.getInstance("AES/CBC/PKCS5Padding");
    
                String line;
                while ((line = reader.readLine()) != null) {
                    String[] headerParts = line.split(":", 5);  // Split into five parts: Mode, Type, IV, Data, Extension
                    if (headerParts.length < 4) continue; // Skip if the format is incorrect
    
                    String mode = headerParts[0];
                    String type = headerParts[1];
                    byte[] iv = Base64.getDecoder().decode(headerParts[2]);
                    byte[] decodedData = Base64.getDecoder().decode(headerParts[3]);
                    String extension = headerParts.length == 5 ? headerParts[4] : "";
    
                    cipherAES.init(Cipher.DECRYPT_MODE, aesKey, new IvParameterSpec(iv));
                    byte[] dataAndHash = cipherAES.doFinal(decodedData);
    
                    // Verify and handle data based on type
                    if (type.equals("file")) {
                        handleFile(dataAndHash, mode, extension);
                    } else if (type.equals("text")) {
                        handleText(dataAndHash, mode);
                    }
                }
    
            } catch (Exception e) {
                System.out.println("Exception in ClientHandler: " + e.getMessage());
                clients.remove(clientId);
            } finally {
                try {
                    clientSocket.close();
                } catch (IOException e) {
                    // Ignore
                }
            }
        }
    
        private void handleFile(byte[] dataAndHash, String mode, String extension) throws IOException {
            // Split the received data and the hash
            byte[] data = Arrays.copyOfRange(dataAndHash, 0, dataAndHash.length - 32);
            byte[] hash = Arrays.copyOfRange(dataAndHash, dataAndHash.length - 32, dataAndHash.length);
    
            // Verify hash
            MessageDigest digest = null;
            try {
                digest = MessageDigest.getInstance("SHA-256");
            } catch (NoSuchAlgorithmException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            byte[] computedHash = digest.digest(data);
            if (!Arrays.equals(hash, computedHash)) {
                System.out.println("Integrity check failed for file from " + clientId);
                return;  // Do not proceed if integrity check fails
            }

            // Ask user for file save location
            FileDialog fileDialog = new FileDialog((Frame) null, "Save file", FileDialog.SAVE);
            fileDialog.setFile("received_" + System.currentTimeMillis() + extension);
            fileDialog.setVisible(true);
            String savePath = fileDialog.getDirectory() + fileDialog.getFile();
    
            // Write file to disk with the specified extension
            try (FileOutputStream fos = new FileOutputStream(new File(savePath))) {
                fos.write(data);
            }
            System.out.println("File received and saved as " + savePath);
            broadcastMessage("File received and saved by server.", clientId);
        }
    
        private void handleText(byte[] dataAndHash, String mode) throws UnsupportedEncodingException {
            byte[] data = Arrays.copyOfRange(dataAndHash, 0, dataAndHash.length - 32);
            byte[] hash = Arrays.copyOfRange(dataAndHash, dataAndHash.length - 32, dataAndHash.length);
    
            // Verify hash
            MessageDigest digest = null;
            try {
                digest = MessageDigest.getInstance("SHA-256");
            } catch (NoSuchAlgorithmException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            byte[] computedHash = digest.digest(data);
            if (!Arrays.equals(hash, computedHash)) {
                System.out.println("Integrity check failed for message from " + clientId);
                return;  // Do not proceed if integrity check fails
            }

            String message = new String(data, StandardCharsets.UTF_8);
            broadcastMessage(message, clientId);
        }
    }
    
    private static PrivateKey loadPrivateKey(String filePath) throws Exception {
        String privateKeyPEM = new String(Files.readAllBytes(Paths.get(filePath)));
        privateKeyPEM = privateKeyPEM.replace("-----BEGIN PRIVATE KEY-----", "").replace("-----END PRIVATE KEY-----", "");
        privateKeyPEM = privateKeyPEM.replaceAll("\\s", "");
        byte[] encoded = Base64.getDecoder().decode(privateKeyPEM);
        PKCS8EncodedKeySpec keySpec = new PKCS8EncodedKeySpec(encoded);
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        return keyFactory.generatePrivate(keySpec);
    }
}
