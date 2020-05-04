class Player:
    def __init__(self, matrix, mark):
        self.matrix = matrix
        self.mark = mark

    def get_coordinates(self):
        x, y = map(int, input("Enter Coordinates: ").strip(" ").split(" "))
        while not (0 <= x <= 2) or not (0 <= y <= 2) or self.matrix[x][y] is not None:
            print("The Entered Coordinate is Invalid. Try again.")
            x, y = map(int, input("Enter Coordinates: ").strip(" ").split(" "))
        return (x, y)

    def place(self, coordinates):
        x, y = coordinates
        self.matrix[x][y] = self.mark

    def play(self):
        coordinates = self.get_coordinates()
        self.place(coordinates)
        return coordinates
