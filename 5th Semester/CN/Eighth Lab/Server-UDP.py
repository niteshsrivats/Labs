from socket import SOCK_DGRAM, socket

serverSocket = socket(type=SOCK_DGRAM)
serverSocket.bind(("10.124.6.72", 8080))
print("Server is ready..")
while True:
    filename, clientAddress = serverSocket.recvfrom(2048)
    filename = filename.decode()
    try:
        file = open(filename, "r")
        data = file.read()
    except:
        data = "File not found"
    serverSocket.sendto(data.encode(), clientAddress)
