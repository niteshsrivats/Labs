import numpy as np

matrix = list()
size = int(input("Enter size of matrix: "))
for i in range(size):
    matrix.append(list(map(int, input().strip(" ").split(" "))))

# size = 12
# matrix = [
#     [0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],#A - 0
#     [1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0],#B - 1
#     [1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0],#C - 2
#     [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],#D - 3
#     [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],#E - 4
#     [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],#F - 5
#     [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1],#G - 6
#     [0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0],#X - 7
#     [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],#Y - 8
#     [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],#Z - 9
#     [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],#I - 10
#     [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0] #J - 11
#     ]

def breadthFirstSearch():
    visited = np.zeros(size)
    for node in range(size):
        if visited[node] == 0:
            visited[node] = 1
            print(bfs(visited, node))

def bfs(visited, node):
    result = [node]
    currentIndex = 0
    resultSize = 1

    while (currentIndex < resultSize):
        node = result[currentIndex]
        for i in range(size):
            if visited[i] == 0 and matrix[node][i] >= 1:
                visited[i] = 1
                result.append(i)
                resultSize += 1
        currentIndex += 1

    return result

breadthFirstSearch()
