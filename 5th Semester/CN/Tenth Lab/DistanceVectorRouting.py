import sys

size = int(input("Enter size: "))
matrix = []
for i in range(size):
    matrix.append(
        list(map(int, input("Enter row " + str(i) + ": ").strip(" ").split(" "))))

for i in range(size):
    for j in range(size):
        if i != j and matrix[i][j] == 0:
            matrix[i][j] = sys.maxsize

nodes = [i for i in range(size)]

for node in nodes:
    remaining_nodes = nodes.copy()
    remaining_nodes.remove(node)
    for selected_node in remaining_nodes:
        if node != selected_node:
            for remaining_node in remaining_nodes:
                if selected_node != remaining_node:
                    matrix[node][selected_node] = min(
                        matrix[node][selected_node], matrix[node][remaining_node] + matrix[remaining_node][selected_node])
for row in matrix:
    print(row)
