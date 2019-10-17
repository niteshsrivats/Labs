import numpy as np

# capacity = int(input("Enter capacity: "))
# weights = list(map(int, input("Enter weights: ").strip(" ").split(" ")))
# values = list(map(int, input("Enter values: ").strip(" ").split(" ")))

capacity = 50
weights = [10, 20, 30]
values = [60, 100, 120]

length = len(weights)
matrix = np.zeros((length, capacity + 1))

for i in range(weights[0], capacity):
    matrix[0][i] = values[0]

for i in range(1, length):
    for j in range(capacity + 1):
        if j - weights[i] >= 0:
            matrix[i][j] = max(matrix[i - 1][j], values[i] +
                               matrix[i - 1][j - weights[i]])
        else:
            matrix[i][j] = matrix[i - 1][j]

print(matrix)
print(matrix[-1][-1])
