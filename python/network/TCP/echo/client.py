from socket import *

SERVER_IP = "localhost"
SERVER_PORT = 8000

# create client socket
clientSocket = socket(AF_INET, SOCK_STREAM)

# connect client socket to server
clientSocket.connect((SERVER_IP, SERVER_PORT))

# get message from user
clientMessage = input("Enter message to send to server: ")

# send message to server
clientSocket.send(clientMessage.encode())

# receive message from server
serverMessage = clientSocket.recv(2048).decode()

print(serverMessage)

# close client socket
clientSocket.close()
