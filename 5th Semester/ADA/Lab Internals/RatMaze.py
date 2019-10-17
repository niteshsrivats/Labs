# Author: K Nitesh Srivats
import numpy as np


def path(x, y, dx, dy):
    if solve(x, y, dx, dy):
        print("Solution doesn't exist")
        return
    print(solution)


def solve(x, y):
    if x == size - 1 and y == size - 1:
        solution[x][y] = 1
        return True
    # course[x][y] == 1 and solution[x][y] == 0
    if 0 <= x < size and 0 <= y < size and matrix[x][y] and solution[x][y]:
        solution[x][y] = 1
        if solve(x + 1, y):
            return True
        if solve(x, y + 1):
            return True
        solution[x][y] = 0
    return False


size = int(input("Enter size of Matrix: "))
matrix = np.zeros((size, size))
solution = np.zeros((size, size), dtype="int8")
path(0, 0)
