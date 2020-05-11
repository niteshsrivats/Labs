import pandas as pd
import math


def getEntropy(data):
    contents = list(data.groupby("Play").size())  # change accordingly
    total = sum(contents)
    if len(contents) == 1:
        return 0
    entropy = -1 * (((contents[0]/total) * math.log2(contents[0]/total)) +
                    ((contents[1]/total) * math.log2(contents[1]/total)))
    return entropy


def calculateColumnEntropy(data, column):
    attributes = set(data[column])
    attributeCount = data.groupby(column).size()
    entropy = 0
    for attribute in attributes:
        current_entropy = getEntropy(data.query(
            column + " == '" + attribute + "'"))
        entropy += attributeCount[attribute] / \
            sum(attributeCount) * current_entropy
    return entropy


def getTree(data):
    tree = {}
    rootEntropy = getEntropy(data)
    if rootEntropy == 0:
        return data["Play"].iloc[0]  # change accordingly

    leastEntropy = 100  # its bleh
    root = None

    columns = list(data.columns)
    columns.remove("Play")  # change accordingly
    for column in columns:
        entropy = calculateColumnEntropy(data, column)
        if entropy < leastEntropy:
            leastEntropy = entropy
            root = column

    subTree = {}
    for attribute in set(data[root]):
        subTree[attribute] = getTree(
            data.query(root + "== '" + attribute + "'"))

    tree[root] = subTree
    return tree


def get_decision(query, tree, nodes):
    if type(tree) == dict:
        node = list(tree.keys())[0]
        node_index = nodes.index(node)
        attribute = query[node_index]
        return get_decision(query, tree[node][attribute], nodes)
    return tree


if __name__ == '__main__':
    data = pd.read_csv("data.csv", dtype="str")
    tree = getTree(data)
    print(tree)
    query = tuple(input("Query: ").strip(" ").split(","))
    print(get_decision(query, tree, list(data.columns.values[:-1])))
