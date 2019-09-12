import numpy as np

# matrix = list()
# size = int(input("Enter size of matrix: "))
# for i in range(size):
#     matrix.append(list(map(int, input().strip(" ").split(" "))))

size = 9
matrix = [[3,0,6,5,0,8,4,0,0], 
          [5,2,0,0,0,0,0,0,0], 
          [0,8,7,0,0,0,0,3,1], 
          [0,0,3,0,1,0,0,8,0], 
          [9,0,0,8,6,3,0,0,5], 
          [0,5,0,0,9,0,6,0,0], 
          [1,3,0,0,0,0,2,5,0], 
          [0,0,0,0,0,0,0,7,4], 
          [0,0,5,2,0,6,3,0,0]]

def get_all_solutions():
    return [1, 2, 3, 4, 5, 6, 7, 8, 9]

def get_column_solutions(matrix, col):
    possible_solutions = get_all_solutions()
    try:
        for i in range(size):
            cell = matrix[i][col]
            if cell != 0 and type(cell) != list:
                possible_solutions.remove(cell)
        return possible_solutions
    except ValueError:
        return list()

def get_row_solutions(matrx, row):
    possible_solutions = get_all_solutions()
    try:
        for i in range(size):
            cell = matrix[row][i]
            if cell != 0 and type(cell) != list:
                possible_solutions.remove(cell)
        return possible_solutions
    except ValueError:
        return list()

def get_box_solutions(matrix, box_row, box_col):
    possible_solutions = get_all_solutions()
    try:
        for i in range(3):
            for j in range(3):
                cell = matrix[i + (box_row * 3)][j + (box_col * 3)]
            if cell != 0 and type(cell) != list:
                possible_solutions.remove(cell)
        return possible_solutions
    except ValueError:
        return list()

def initialize(matrix):
    for i in range(size):
        row_solution = get_row_solutions(matrix, i)
        for j in range(size):
            if matrix[i][j] == 0:
                matrix[i][j] = row_solution

    for j in range(size):
        col_solution = set(get_column_solutions(matrix, j))
        for i in range(size):
            if type(matrix[i][j]) == list:
                matrix[i][j] = list(set(matrix[i][j]).intersection(col_solution))
    
    for box_row in range(3):
        for box_col in range(3):
            box_solution = get_box_solutions(matrix, box_row, box_col)
            for i in range(3):
                for j in range(3):
                    if type(matrix[i + (box_row * 3)][j + (box_col) * 3]) == list:
                        matrix[i + (box_row * 3)][j + (box_col * 3)] = list(set(matrix[i + (box_row * 3)][j + (box_col) * 3]).intersection(box_solution))
                        temp = len(matrix[i + (box_row * 3)][j + (box_col) * 3]) 
                        if temp == 0:
                            matrix[i + (box_row * 3)][j + (box_col) * 3] = 0
                        elif temp == 1:
                            matrix[i + (box_row * 3)][j + (box_col) * 3] = matrix[i + (box_row * 3)][j + (box_col) * 3][0]


def get_cell_solution(matrix, row, col):
    result = set(get_column_solutions(matrix, col))
    result = result.intersection(set(get_row_solutions(matrix, row)))
    result = result.intersection(set(get_box_solutions(matrix, int(row / 3), int(col / 3))))
    return result

def find_empty_location(matrix):
    for i in range(9):
        for j in range(9):
            if type(matrix[i][j]) == list or matrix[i][j] == 0:
                return i, j
    return -1, -1

def solve_sudoku(matrix):
    i, j = find_empty_location(matrix)
    if i == -1:
        return True

    solutions = matrix[i][j]
    if matrix[i][j] == 0:
        solutions = get_cell_solution(matrix, i, j)
        
    for solution in solutions:
        matrix[i][j] = solution
        if solve_sudoku(matrix):
            return True
    return False

def display(matrix):
    for i in range(size):
        for j in range(size):
            print(matrix[i][j], end=' ')
        print()

initialize(matrix)
solve_sudoku(matrix)
display(matrix)
