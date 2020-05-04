class Node:
    def __init__(self, parent, board, cost):
        super().__init__()
        self.board = board
        self.parent = parent
        self.g = cost
        self.h = 0
        self.f = self.h + self.g

    def __str__(self):
        return self.board

    def __eq__(self, value):
        if not isinstance(value, Node) or self.board != value.board:
            # don't attempt to compare against unrelated types
            return False
        return True

    def print_steps(self):
        node = self
        while node is not None:
            print(node.board)
            node = node.parent

    def make_move(self, i1, i2):
        sequence_list = list(self.board)
        sequence_list[i1], sequence_list[i2] = sequence_list[i2], sequence_list[i1]
        return ''.join(sequence_list)

    def get_possible_moves(self):
        possible_moves_list = {
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

        zero_index = self.board.index('0')
        moves = possible_moves_list[zero_index]
        results = []

        for move in moves:
            results.append(self.make_move(zero_index, move))

        return results

    def calculate_heuristic(self):
        return self.calculate_manhattan_distance() + (2 * self.calculate_linear_conflict())

    def calculate_manhattan_distance(self):
        distance = 0
        for index in range(9):
            value = self.board[index]
            if value == '0':
                continue

            row = index // 3
            column = index % 3

            goal_row, goal_column = self.get_goal_coordinate(value)

            distance += (abs(row - goal_row) + abs(column - goal_column))

    def calculate_linear_conflict(self):
        conflicts = 0
        index = 0
        pairs = 0
        while pairs != 4:
            value = self.board[index]
            if value == '0':
                index += 1
                continue

            goal_index = self.get_goal_index(value)

            if goal_index != index:
                expected_value = self.board.index(goal_index)
                expected_value_goal_index = self.get_goal_index(expected_value)

                if expected_value_goal_index == index:
                    conflicts += 1

            index += 1
            pairs += 1

        return conflicts

    def get_goal_coordinate(self, value):
        goal_index = self.get_goal_index(value)
        goal_row = goal_index // 3
        goal_column = goal_index % 3

        return (goal_row, goal_column)

    def get_goal_index(self, value):
        return '123456780'.index(value)
