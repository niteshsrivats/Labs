import numpy as np

size = int(input("Enter Size: "))
matrix = list()
for i in range(size):
    matrix.append(list(map(int, input().strip(" ").split(" "))))
# matrix = [[0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 0], [1, 0, 0, 0]]
matrix = np.array(matrix)
indegree = np.zeros((size, ))


def topologicalSort():
    order = list()
    indegree = np.zeros((size, ))
    for i in range(size):
        indegree[i] = np.sum(matrix[:, i])

    for i in range(size):
        vertex = -1

        for k in range(size):
            if indegree[k] == 0:
                order.append(k)
                indegree[k] = -1
                vertex = k
                break
        if vertex == -1:
            return False

        for j in range(size):
            if matrix[vertex][j] == 1:
                indegree[j] -= 1
    return order


print(topologicalSort())
