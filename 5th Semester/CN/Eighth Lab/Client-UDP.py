from socket import SOCK_DGRAM, socket

clientSocket = socket(type=SOCK_DGRAM)
filename = input("Enter filename")
clientSocket.sendto(filename.encode(), ("127.0.0.1", 8080))
content, serverAddress = clientSocket.recvfrom(4096)
print(content.decode())
clientSocket.close()
