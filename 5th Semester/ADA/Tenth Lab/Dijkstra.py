import sys

size = int(input("Enter number of nodes: "))
source = int(input("Enter source node: "))
matrix = list()
for i in range(size):
    matrix.append(list(map(int, input("Enter row " + str(i) + ": ").strip(" ").split(" "))))

nodes = [i for i in range(size) if i != source]
path = [[[] for i in range(size)]]
visited = [source]

for _ in range(size - 1):
    source_node, destination_node, min_weight = None, None, sys.maxsize
    
    # Find shortest distance
    for visited_node in visited:
        for j in nodes:
            if matrix[visited_node][j] != 0 and matrix[visited_node][j] < min_weight:
                source_node, destination_node, min_weight = visited_node, j, matrix[visited_node][j]
    
    # Update total distances
    for i in nodes:
        if matrix[destination_node][i] != 0:
            matrix[destination_node][i] += matrix[source_node][destination_node]
    
    matrix[source][destination_node] = matrix[source_node][destination_node]
    visited.append(destination_node)
    nodes.remove(destination_node)
    
    path[source][destination_node].extend(path[source][source_node])
    path[source][destination_node].append(source_node)

for i in range(size):
    print("Source", source, "-", "Destination", str(i) + ":", matrix[source][i]) 
    print("Path:", path[source][i])
