
# Multi-Client Secure Communication System

## Course Information
**Course:** CSE 439 - Computer Security  
**Instructor:** Onur Demir  
**University:** Yeditepe University  
**Semester:** Spring 2024

## Project Description
This project aims to develop a client-server application that enables secure communication among multiple clients connected to a server. The project extends a previously implemented system by introducing group communication, where all clients in a group can exchange messages and files securely. The communication is encrypted using a single key encryption algorithm to ensure confidentiality. The system supports text messaging and file sharing, with a maximum file size limit of 50 MB. The project also includes modes to ensure both confidentiality and integrity of the communication.

## Project Demo
https://github.com/user-attachments/assets/914676e7-5874-433f-b5ed-a8276cc9128f

## Features
- **Client-Server Architecture**: Establishes a connection-oriented communication model between clients and a central server.
- **Secure Communication**: Implements encryption for all messages and files using AES, with RSA for key exchange.
- **Group Messaging**: Supports broadcasting of messages to all connected clients within a group.
- **File Sharing**: Allows clients to upload and download files with a size limit of 50 MB.
- **Confidentiality and Integrity Modes**: Provides options to run the application in modes that focus on either confidentiality or integrity.
- **Error Handling**: Includes mechanisms to handle client failures without disrupting the system.

## Technologies Used
- **Programming Languages:** Java
- **Frameworks/Libraries:** Java Standard Library (including `javax.crypto`, `java.awt`, and others)

## Installation and Setup
Follow these steps to set up and run the project locally.

```bash
# Clone the repository
git clone https://github.com/burakaslantas/YeditepeCSE.git
cd "YeditepeCSE/CSE 439 - Computer Security"

# Compile the Java files
javac Server.java Client.java

# Run the server
java Server

# Run the client (in separate terminal windows to simulate multiple clients)
java Client
```

**Dependencies**:
- Java Development Kit (JDK) 8 or higher

## Usage Instructions
1. **Running the Server**: Start the server first using the command `java Server`. The server will listen for client connections on the specified port.
2. **Connecting Clients**: Start multiple clients using the command `java Client`. Each client will join the group and can send messages or files.
3. **Testing Modes**:
   - **Confidentiality Mode**: Run the application normally to ensure all communications are encrypted.
   - **Integrity Mode**: Modify the server and client settings to enable integrity checks during communication.

## Project Structure
- **`Client.java`**: Handles the client-side logic, including the GUI, encryption, and communication with the server.
- **`Server.java`**: Manages server-side operations, including client connections, message broadcasting, and file handling.
- **`public_key.pem`**, **`private_key.pem`**: RSA public and private keys used for encryption.
- **`run_test.sh`**: A shell script for testing the system.
- **`burak_aslantas_documentation.pdf`**: Detailed documentation of the project.

## Additional Information
Refer to the [documentation](burak_aslantas_documentation.pdf) for more details about the architecture, implementation, and potential issues encountered during development.

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Acknowledgments
Special thanks to the course instructors and peers for their support and guidance throughout this project.
