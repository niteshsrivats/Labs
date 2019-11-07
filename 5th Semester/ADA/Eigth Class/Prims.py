import sys
import numpy as np

def prims(matrix, size):
    solution = list()
    selected_nodes = [0]
    remaining_nodes = [i for i in range(1, size)]
    path_weight = 0
    for _ in range(size - 1):
        min_weight, min_path = sys.maxsize, None
        for selected_node in selected_nodes:
            for remaining_node in remaining_nodes:
                if matrix[remaining_node][selected_node] != 0 and matrix[remaining_node][selected_node] < min_weight:
                    min_weight = matrix[remaining_node][selected_node]
                    min_path = [selected_node, remaining_node]

        selected_nodes.append(min_path[1])
        remaining_nodes.remove(min_path[1])
        path_weight += min_weight
        solution.append([min_path, min_weight])

    return solution, path_weight

size = int(input("Enter Number of Nodes: "))
matrix = list()
for i in range(size):
    matrix.append(list(map(int, input("Enter Row " + str(i) + " : ").strip(" ").split(" "))))

print(prims(matrix, size))
