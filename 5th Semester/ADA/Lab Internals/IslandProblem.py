import numpy as np


def vertical_check(i, j):
    if j != 0:
        check(i, j - 1)
    if j != size - 1:
        check(i, j + 1)


def check(i, j):
    global matrix, path_matrix
    if matrix[i][j] == 0:
        return
    else:
        path_matrix[i][j] = 1
        matrix[i][j] = 0

    vertical_check(i, j)

    if i != 0:
        check(i - 1, j)
        vertical_check(i - 1, j)

    if i != size - 1:
        check(i + 1, j)
        vertical_check(i + 1, j)


size = int(input("Enter size of matrix: "))
matrix = np.reshape(np.array(np.random.random_sample(
    size * size) * 2, dtype='i4'), (size, size))
path_matrix = np.zeros((size, size))
print(matrix)

islands = 0
for i in range(size):
    for j in range(size):
        if matrix[i][j] != 0:
            check(i, j)
            islands += 1
            print("\nIsland:", islands, "\n", path_matrix)
            path_matrix = np.zeros((size, size))

print("\nTotal Islands:", islands)
