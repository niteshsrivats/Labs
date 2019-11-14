size = int(input("Enter number of nodes: "))
matrix = list()
for i in range(size):
    matrix.append(list(map(int, input("Enter row " + str(i) + ": ").strip(" ").split(" "))))

for intermediate in range(size):
    for i in range(size):
        if intermediate != i:
            for j in range(size):
                if i != j and intermediate != j and matrix[i][intermediate] != 0 and matrix[intermediate][j] != 0:
                    if matrix[i][j] == 0:
                        matrix[i][j] = matrix[i][intermediate] + matrix[intermediate][j]
                    else:
                        matrix[i][j] = min(matrix[i][j], matrix[i][intermediate] + matrix[intermediate][j])

for row in matrix:
    print(row)
