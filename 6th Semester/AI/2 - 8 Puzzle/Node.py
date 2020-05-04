class Node:
    def __init__(self, current, previous=[]):
        super().__init__()
        self.current = current
        self.previous = previous

    def __str__(self):
        return "current: " + self.current + "\nprevious: " + ', '.join(self.previous)
