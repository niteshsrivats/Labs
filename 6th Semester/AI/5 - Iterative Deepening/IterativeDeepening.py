# Implement iterative deepening search to solve 8 puzzle problem

import copy


def printBoard(board):
    for row in board:
        print(row)


def findZeroPosition(currentState):
    for row in range(3):
        for col in range(3):
            if currentState[row][col] == 0:
                return (row, col)


def getNextStates(currentState):
    nextStates = []
    row, col = findZeroPosition(currentState)

    if row > 0:
        temp = copy.deepcopy(currentState)
        temp[row][col], temp[row - 1][col] = temp[row - 1][col],  temp[row][col]
        nextStates.append(temp)

    if col < 2:
        temp = copy.deepcopy(currentState)
        temp[row][col], temp[row][col + 1] = temp[row][col + 1], temp[row][col]
        nextStates.append(temp)

    if row < 2:
        temp = copy.deepcopy(currentState)
        temp[row][col], temp[row + 1][col] = temp[row + 1][col],  temp[row][col]
        nextStates.append(temp)

    if col > 0:
        temp = copy.deepcopy(currentState)
        temp[row][col], temp[row][col - 1] = temp[row][col - 1], temp[row][col]
        nextStates.append(temp)

    return nextStates


def dfs(route, currentState, goalState, depth):

    if currentState == goalState:
        return route

    if depth <= 0:
        return

    for nextState in getNextStates(currentState):
        if(nextState not in route):
            nextRoute = dfs(route + [nextState],
                            nextState, goalState, depth - 1)
            if(nextRoute):
                return nextRoute


def iterativeSearch(currentState, goalState):
    depth = 1
    while True:
        print("Depth: ", depth)
        route = dfs([currentState], currentState, goalState, depth)
        if route:
            print("Goal reached")
            return route
        depth += 1


def printSolutionRoute(route):
    print("Solution: ")
    for step, state in enumerate(route):
        print("Step: ", step)
        printBoard(state)


if __name__ == "__main__":
    initialState = [[1, 5, 2], [4, 8, 0], [7, 6, 3]]
    goalState = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
    print("Initial state")
    printBoard(initialState)

    route = iterativeSearch(initialState, goalState)

    # printSolutionRoute(route)
