import random


class Bot:
    def __init__(self, matrix, mark, check_finish):
        self.check_finish = check_finish
        self.matrix = matrix
        self.mark = mark
        self.placed = []
        if mark == "x":
            self.opponent = "o"
        else:
            self.opponent = "x"

    def get_winning_point(self):
        for i in range(3):
            for j in range(3):
                if self.matrix[i][j] is None:
                    self.matrix[i][j] = self.mark
                    if self.check_finish(self.matrix, (i, j)):
                        self.matrix[i][j] = None
                        return (i, j)
                    else:
                        self.matrix[i][j] = None
        return None

    def get_defending_point(self):
        for i in range(3):
            for j in range(3):
                if self.matrix[i][j] is None:
                    self.matrix[i][j] = self.opponent
                    if self.check_finish(self.matrix, (i, j)):
                        self.matrix[i][j] = None
                        return (i, j)
                    else:
                        self.matrix[i][j] = None
        return None

    def get_best_move(self):
        for coordinates in self.placed:
            x, y = coordinates
            if self.matrix[x][y] is self.mark:
                self.matrix[x][y] = None

                # Major Diagonal
                if x == y and self.matrix[0][0] == self.matrix[1][1] == self.matrix[2][2]:
                    self.matrix[x][y] = self.mark
                    k = random.randint(0, 2)
                    while k == x:
                        k = random.randint(0, 2)
                    return (k, k)

                # Minor Diagonal
                if x == y and self.matrix[0][2] == self.matrix[1][1] == self.matrix[2][0]:
                    self.matrix[x][x] = self.mark
                    k = random.randint(0, 2)
                    while k == x:
                        k = random.randint(0, 2)
                    return (k, 2 - k)

                # Empty Column
                if self.matrix[0][y] == self.matrix[1][y] == self.matrix[2][y]:
                    self.matrix[x][y] = self.mark
                    k = random.randint(0, 2)
                    while k == x:
                        k = random.randint(0, 2)
                    return (k, y)

                # Empty Row
                if self.matrix[x][0] == self.matrix[x][1] == self.matrix[x][2]:
                    self.matrix[x][y] = self.mark
                    k = random.randint(0, 2)
                    while k == y:
                        k = random.randint(0, 2)
                    return (x, k)

                self.matrix[x][y] = self.mark

        return None

    def random_move(self):
        if self.matrix[1][1] is None:
            return (1, 1)
        x, y = random.randint(0, 2), random.randint(0, 2)
        while self.matrix[x][y] is not None:
            x, y = random.randint(0, 2), random.randint(0, 2)
        return (x, y)

    def place(self):
        coordinates = self.get_winning_point()
        if coordinates is None:
            coordinates = self.get_defending_point()

        if coordinates is None:
            coordinates = self.get_best_move()

        if coordinates is None:
            coordinates = self.random_move()
        x, y = coordinates
        self.matrix[x][y] = self.mark
        self.placed.append((x, y))
        return coordinates

    def play(self):
        coordinates = self.place()
        print("Bot Played at:", coordinates)
        return coordinates
