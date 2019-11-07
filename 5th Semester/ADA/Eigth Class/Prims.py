import sys
import numpy as np

# size = int(input("Enter Number of Nodes: "))
size = 5
nodes = [i for i in range(size)]
matrix = list()
matrix = [[0, 2, 0, 6, 0], 
            [2, 0, 3, 8, 5], 
            [0, 3, 0, 0, 7], 
            [6, 8, 0, 0, 9], 
            [0, 5, 7, 9, 0]]
solution = []
path_weight = 0

# for i in range(size):
#     matrix.append = list(map(int, input("Enter Row " + str(i) + " : ")))
selected_nodes = [nodes.pop()]
for i in range(size - 1):
    min_weight, min_node, selected_min_node = sys.maxsize, None, None
    for selected_node in selected_nodes:
        for remaining_node in nodes:
            if matrix[remaining_node][selected_node] != 0 and matrix[remaining_node][selected_node] < min_weight:
                min_weight = matrix[remaining_node][selected_node]
                min_node = remaining_node
                selected_min_node = selected_node
    selected_nodes.append(min_node)
    path_weight += min_weight
    solution.append([selected_min_node, min_node, min_weight])
    nodes.remove(min_node)
print(solution, path_weight)

