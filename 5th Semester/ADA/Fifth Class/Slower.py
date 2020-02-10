
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

def display(matrix):
    for i in range(size):
        for j in range(size):
            print(matrix[i][j], end=' ')
        print()
  
def get_empty_location(matrix): 
    for row in range(9): 
        for col in range(9): 
            if(matrix[row][col] == 0): 
                return row, col
    return -1, -1

def row_check(matrix, row, num): 
    for i in range(9): 
        if(matrix[row][i] == num): 
            return False
    return True
  
def col_check(matrix, col, num): 
    for i in range(9): 
        if(matrix[i][col] == num): 
            return False
    return True
  
def box_check(matrix, row, col, num): 
    for i in range(3): 
        for j in range(3): 
            if(matrix[i + row][j + col] == num): 
                return False
    return True

def check_location_is_safe(matrix, row, col, num): 
    return row_check(matrix, row, num) and col_check(matrix, col, num) and box_check(matrix,row - row % 3,col - col % 3,num) 
  
def solve_sudoku(matrix): 
    row, col = get_empty_location(matrix)
    if row == -1:
        return True

    for num in [1, 2, 3, 4, 5, 6, 7, 8, 9]:
        if(check_location_is_safe(matrix,row,col,num)): 
            matrix[row][col]=num 
            if solve_sudoku(matrix): 
                return True
            matrix[row][col] = 0
                     
    return False 

solve_sudoku(matrix)
display(matrix) 