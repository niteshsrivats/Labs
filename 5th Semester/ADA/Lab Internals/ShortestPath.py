import numpy as np
import sys
matrix = list()
size = int(input("Enter size of matrix: "))
for i in range(size):
    matrix.append(list(map(str, input().strip(" ").split(" "))))
sourceX, sourceY, destinationX, destinationY = map(int, input(
    "Enter source and destination index: ").strip(" ").split(" "))
# matrix = [[0, 1, 0, 1], [1, 0, 1, 1], [0, 1, 1, 1], [1, 1, 1, 1]]
# sourceX, sourceY, destinationX, destinationY = 0, 3, 3, 0
distanceMin = sys.maxsize


def shortestPath(matrix, sourceX, sourceY, destinationX, destinationY, visited=np.zeros((size, size)), distance=0):
    global distanceMin
    visited[sourceX][sourceY] = 1
    if matrix[sourceX][sourceY]:
        if sourceX != destinationX:
            if sourceX > 0 and visited[sourceX - 1][sourceY] == 0:
                shortestPath(matrix, sourceX - 1, sourceY,
                             destinationX, destinationY, visited, distance + 1)
            if sourceX < size - 1 and visited[sourceX + 1][sourceY] == 0:
                shortestPath(matrix, sourceX + 1, sourceY,
                             destinationX, destinationY, visited, distance + 1)
        if sourceY != destinationY:
            if sourceY > 0 and visited[sourceX][sourceY - 1] == 0:
                shortestPath(matrix, sourceX, sourceY - 1,
                             destinationX, destinationY, visited, distance + 1)
            if sourceY < size - 1 and visited[sourceX][sourceY + 1] == 0:
                shortestPath(matrix, sourceX, sourceY + 1,
                             destinationX, destinationY, visited, distance + 1)
        if sourceX == destinationX and sourceY == destinationY:
            if distanceMin > distance:
                distanceMin = distance
    return


shortestPath(matrix, sourceX, sourceY, destinationX, destinationY)
print(distanceMin)
