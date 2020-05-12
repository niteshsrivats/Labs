from Player import Player
from Bot import Bot

def check_finish(matrix, coordinates):
    x, y = coordinates
    # Diagonals
    if x == y and matrix[0][0] == matrix[1][1] == matrix[2][2]:
        return True
    elif x == abs(y - 2) and matrix[0][2] == matrix[1][1] == matrix[2][0]:
        return True

    # Row
    if matrix[0][y] == matrix[1][y] == matrix[2][y]:
        return True

    # Column
    if matrix[x][0] == matrix[x][1] == matrix[x][2]:
        return True

    return False


class Game:
    def __init__(self, check_finish):
        self.check_finish = check_finish
        self.matrix = [[None for i in range(3)] for j in range(3)]
        self.bot = Bot(self.matrix, "x", check_finish)
        self.player = Player(self.matrix, "o")
        self.player_turn = True

    def display(self):
        for i in range(3):
            for j in range(3):
                if self.matrix[i][j] is None:
                    print(end="_ ")
                else:
                    print(self.matrix[i][j], end=" ")
            print()



    def place(self):
        if self.player_turn:
            self.player_turn = False
            coordinates = self.player.play()
            if self.check_finish(self.matrix, coordinates):
                print("Player Won.")
                return True
        else:
            self.player_turn = True
            coordinates = self.bot.play()
            if self.check_finish(self.matrix, coordinates):
                print("Bot Won.")
                return True
        return False

    def play(self):
        count = 0
        self.display()
        while not self.place():
            if count == 8:
                print("It's a Tie.")
                break
            self.display()
            count += 1
        self.display()


if __name__ == "__main__":
    game = Game(check_finish)
    game.play()
