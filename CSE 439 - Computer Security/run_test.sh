#!/bin/bash

# Define paths to the Java files
SERVER_JAVA_PATH="./Server.java"
CLIENT_JAVA_PATH="./Client.java"

# Check if Java files exist
if [[ ! -f "$SERVER_JAVA_PATH" ]]; then
    echo "Server Java file not found at $SERVER_JAVA_PATH"
    exit 1
fi

if [[ ! -f "$CLIENT_JAVA_PATH" ]]; then
    echo "Client Java file not found at $CLIENT_JAVA_PATH"
    exit 1
fi

# Compile the Java files
echo "Compiling Server.java..."
javac "$SERVER_JAVA_PATH"
if [ $? -ne 0 ]; then
    echo "Error compiling Server.java"
    exit 1
fi

echo "Compiling Client.java..."
javac "$CLIENT_JAVA_PATH"
if [ $? -ne 0 ]; then
    echo "Error compiling Client.java"
    exit 1
fi

# Start the server in the background and save its PID
echo "Starting the server..."
java Server &
SERVER_PID=$!

# Wait a bit for the server to initialize
sleep 2

# Run the client
echo "Running the client..."
java Client

# Kill the server process after the client has finished
echo "Shutting down the server..."
kill $SERVER_PID

echo "Demo completed."
