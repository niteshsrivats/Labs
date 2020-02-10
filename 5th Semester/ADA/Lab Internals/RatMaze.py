import numpy as np


def path(x, y):
    if not solve(x, y):
        print("Solution doesn't exist")
        return
    print(solution)


def solve(x, y):
    if x == size - 1 and y == size - 1:
        solution[x][y] = 1
        return True
    if 0 <= x < size and 0 <= y < size and matrix[x][y]:
        solution[x][y] = 1
        if solve(x + 1, y):
            return True
        if solve(x, y + 1):
            return True
        solution[x][y] = 0
    return False


size = int(input("Enter size of Matrix: "))
matrix = np.reshape(np.array((np.random.random_sample(size * size) * 2),
                             dtype="int8"), (size, size))
solution = np.zeros((size, size), dtype="int8")
path(0, 0)
