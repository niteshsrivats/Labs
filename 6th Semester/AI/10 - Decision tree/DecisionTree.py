import math
from sys import maxsize

import numpy as np

nodes = list()
output_node = str()
dataset = np.array([])
decision_tree = dict()


def get_count_map(values):
    values_count = dict()
    for value in values:
        if value in values_count.keys():
            values_count[value] += 1
        else:
            values_count[value] = 1
    return values_count


def calculate_entropy(values):
    values_count = get_count_map(values)
    total_keys = len(values_count.keys())

    if total_keys == 1:
        return 0

    total_values = len(values)
    result = 0

    for value in values_count:
        fraction = values_count[value] / total_values

        result -= fraction * math.log(fraction, total_keys)
    return result


def create_tree(selected, order):
    if len(nodes) == len(order):
        return

    final_node = {'node': {}, 'attributes': {}, 'entropy': {}, 'net-entropy': maxsize}
    for node in nodes:
        if node not in order:
            # Unselected node in sub tree
            node_index = nodes.index(node)
            attributes = {attribute: {'data': [], 'count': 0} for attribute in set(dataset[:, node_index])}
            total_attributes = 0

            for row in dataset:
                for attribute in attributes:
                    if row[node_index] == attribute:
                        insert = True
                        # Ensure the path to the attribute node is the same
                        for selected_node in selected:
                            selected_index = nodes.index(selected_node)
                            if row[selected_index] != selected[selected_node]:
                                insert = False
                                break

                        if insert:
                            attributes[attribute]['data'].append(row[-1])
                            attributes[attribute]['count'] += 1
                            total_attributes += 1

            attribute_entropy = {attribute: calculate_entropy(attributes[attribute]['data'])
                                 for attribute in attributes}

            entropy = 0
            for attribute in attributes:
                entropy += (attributes[attribute]['count'] / total_attributes) * attribute_entropy[attribute]

            if entropy < final_node['net-entropy']:
                final_node = {'node': node, 'attributes': attributes, 'entropy': attribute_entropy,
                              'net-entropy': entropy}

    sub_tree = decision_tree
    for node in order:
        sub_tree = sub_tree[node][selected[node]]

    sub_tree[final_node['node']] = {}
    sub_tree = sub_tree[final_node['node']]

    order_copy = order.copy()
    order_copy.append(final_node['node'])
    for attribute in final_node['attributes']:
        if final_node['entropy'][attribute] == 0 or len(nodes) - len(order) == 1:
            sub_tree[attribute] = final_node['attributes'][attribute]['data'][0]
        else:
            sub_tree[attribute] = {}
            selected_copy = selected.copy()
            selected_copy[final_node['node']] = attribute
            create_tree(selected_copy, order_copy)


def get_decision(query, tree):
    if type(tree) == dict:
        node = list(tree.keys())[0]
        node_index = nodes.index(node)
        attribute = query[node_index]
        return get_decision(query, tree[node][attribute])
    return tree


def main():
    global output_node, nodes, dataset
    data = list()
    with open("data.csv", "r") as file:
        index = 0
        for line in file:
            row = line.strip("\n").split(", ")
            if index == 0:
                output_node = row.pop(-1)
                nodes = row
                index += 1
            else:
                data.append(row)
    dataset = np.array(data)
    create_tree(selected={}, order=[])


if __name__ == '__main__':
    main()
    print(decision_tree)
    query = tuple(input("Query: ").strip(" ").split(", "))
    print(get_decision(query, decision_tree))
