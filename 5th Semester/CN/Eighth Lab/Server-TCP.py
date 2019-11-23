from socket import socket

serverSocket = socket()
serverSocket.bind(("10.124.6.72", 8080))
serverSocket.listen(1)
print("The server is ready to receive ")
while True:
    connectionSocket, addr = serverSocket.accept()
    fileName = connectionSocket.recv(1024)
    fileName = fileName.decode()
    try:
        file = open(fileName, "r")
        data = file.read()
    except:
        data = "File not found"
    connectionSocket.send(data.encode())
    connectionSocket.close()
