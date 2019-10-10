import numpy as np

size = int(input("Enter size of Board: "))
matrix = np.zeros((size, size))


def is_safe(matrix, row, col, size):
    for i in range(row):
        if matrix[i][col] == 1:
            return False

    for i in range(1, min(row, size - col)):
        if matrix[row - i][col + i] == 1:
            return False

    for i in range(1, min(row, col) + 1):
        if matrix[row - i][col - i] == 1:
            return False
    return True


solutions = list()
def queen(row=0):
    global matrix
    flag = False
    for i in range(size):
        if is_safe(matrix, row, i, size):
            matrix[row][i] = 1
            if row == size - 1:
                solutions.append(matrix.copy())
                flag = True
            if queen(row + 1):
                if row == 0:
                    matrix = np.zeros((size, size))
                else:
                    return True
            matrix[row][i] = 0
    return flag


queen()
for solution in solutions:
    print(solution)
print(len(solutions))
