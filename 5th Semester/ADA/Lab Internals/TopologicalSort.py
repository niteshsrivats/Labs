import numpy as np

size = int(input("Enter Size: "))
matrix = np.zeros((size, size))
pairs = list(map(str, input("Enter pairs: ").lstrip(
    "[").rstrip("]").split(", ")))
for i in range(0, len(pairs), 2):
    matrix[int(pairs[i].lstrip("["))][int(pairs[i + 1].rstrip("]"))] = 1
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
