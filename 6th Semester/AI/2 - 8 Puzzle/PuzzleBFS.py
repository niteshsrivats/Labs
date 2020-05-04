from Node import Node

possible_moves = {
    0: [1, 3],
    1: [0, 2, 4],
    2: [1, 5],
    3: [0, 4, 6],
    4: [1, 3, 5, 7],
    5: [2, 4, 8],
    6: [3, 7],
    7: [4, 6, 8],
    8: [5, 7]
}


def check_result(sequence):
    if sequence == "123456780":
        return True
    return False


def make_move(sequence, i1, i2):
    sequence_list = list(sequence)
    sequence_list[i1], sequence_list[i2] = sequence_list[i2], sequence_list[i1]
    return ''.join(sequence_list)


def get_move_results(sequence):
    zero_index = sequence.index('0')
    moves = possible_moves[zero_index]
    results = []

    for move in moves:
        results.append(make_move(sequence, zero_index, move))

    return results


if __name__ == "__main__":
    sequence = input("Sequence: ")
    # 123046758

    if check_result(sequence):
        print("You entered the solution.")

    nodes = [Node(sequence)]

    num_moves, num_nodes = 0, 0

    while nodes:
        nodes_in_level = len(nodes)
        num_moves += 1

        for _ in range(nodes_in_level):
            node = nodes.pop(0)
            num_nodes += 1

            moves = get_move_results(node.current)

            previous = node.previous.copy() + [node.current]

            for move in moves:
                if check_result(move):
                    print("Number of moves - " + str(num_moves))
                    print("Number of traversed nodes - " + str(num_nodes))
                    exit()

                if move not in node.previous:
                    nodes.append(Node(move, previous))
