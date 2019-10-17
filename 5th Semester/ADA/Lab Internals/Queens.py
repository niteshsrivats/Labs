import numpy as np

size = int(input("Enter size of Board: "))
matrix = np.zeros((size, size))
solutions = list()


def is_safe(matrix, row, col, size):
    for i in range(row):
        if matrix[i][col] == 1:
            return False

    for i in range(1, min(row + 1, size - col)):
        if matrix[row - i][col + i] == 1:
            return False

    for i in range(1, min(row, col) + 1):
        if matrix[row - i][col - i] == 1:
            return False
    return True


def queen(matrix, row=0):
    for i in range(size):
        if is_safe(matrix, row, i, size):
            matrix[row][i] = 1
            if row == size - 1:
                solutions.append(matrix.copy())
            queen(matrix, row + 1)
            matrix[row][i] = 0


queen(matrix)
for solution in solutions:
    print(solution)
