import numpy as np

matrix = list()
size = int(input("Enter size of matrix: "))
for i in range(size):
    matrix.append(list(map(int, input().strip(" ").split(" "))))

def depthFirstSearch():
    visited = np.zeros(size)
    for node in range(size):
        if visited[node] == 0:
            print(dfs(visited, node))

def dfs(visited, node):
    connected = [node]
    visited[node] = 1
    for i in range(size):
        if  visited[i] == 0 and matrix[node][i] == 1:
            connected.extend(dfs(visited, i))
    return connected

depthFirstSearch()
