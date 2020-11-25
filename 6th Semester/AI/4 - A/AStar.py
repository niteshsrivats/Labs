from Node import Node


def AStar():
    start = Node(None, "123046758", 0)
    open_list = {0: [start]}
    closed_list = []

    while len(open_list) != 0:
        move = get_closest_node(open_list, closed_list)

        if move is None:
            print("No Solution")
        else:
            possible_moves = move.get_possible_moves()
            for possible_move in possible_moves:
                if possible_move == '123456780':
                    print(possible_move)
                    move.print_steps()
                    return

                if possible_move not in closed_list:
                    possible_move_node = Node(move, possible_move, move.g + 1)
                    f = possible_move_node.f

                    if f in open_list.keys():
                        found = False
                        for i in range(len(open_list[f])):
                            node = open_list[f][i]
                            if node.board == possible_move:
                                found = True
                                if node.f > possible_move_node.f:
                                    open_list[f].pop(i)
                                    open_list[f].append(possible_move_node)
                        if not found:
                            open_list[f].append(possible_move_node)
                    else:
                        open_list[f] = [possible_move_node]


def get_closest_node(open_list, closed_list):
    f = min(open_list.keys())

    possible_moves = open_list[f]
    possible_move = possible_moves.pop()
    closed_list.append(possible_move.board)

    if len(possible_moves) == 0:
        open_list.pop(f)

    return possible_move


if __name__ == "__main__":
    AStar()
