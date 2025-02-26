from socket import *

SERVER_IP = "localhost"
SERVER_PORT = 8000

# create server socket
serverSocket = socket(AF_INET, SOCK_STREAM)

# bond server socket to IP address and port number
serverSocket.bind((SERVER_IP, SERVER_PORT))

# set listening socket to listen for incoming connections from clients
serverSocket.listen(1)

while True:
    # accept connection request from client
    connectionSocket, clientAddress = serverSocket.accept()

    print("Connection accepted")

    # receive message
    clientMessage = connectionSocket.recv(2048).decode()

    print(clientMessage, clientAddress)

    # set message to uppercase
    serverMessage = clientMessage.upper()

    # send message back to client
    connectionSocket.send(serverMessage.encode())

    connectionSocket.close()
