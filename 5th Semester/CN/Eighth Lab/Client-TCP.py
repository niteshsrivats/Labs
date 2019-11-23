from socket import socket

clientSocket = socket()
clientSocket.connect(("127.0.0.1", 8080))
filename = input("Enter the name of the file ")
clientSocket.send(filename.encode())
message = clientSocket.recv(1024)
print(message.decode())
clientSocket.close()
