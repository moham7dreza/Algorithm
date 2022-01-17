def solve(bo):
    row, col = next_empty(bo)
    if row == -1 and col == -1:
        return True

    for candida in range(1,10):
        if check(bo, candida, row, col):
            bo[row][col] = candida
            if solve(bo):
                return True
            bo[row][col] = 0
    
    return False


def check(bo, candida, row, col):
    for i in range(9):
        # check row
        if bo[row][i] == candida and col != i:
            return False
        # check column
        if bo[i][col] == candida and row != i:
            return False
    
    # Check box
    box_x = col // 3
    box_y = row // 3
    for i in range(3 * box_y, 3 * (box_y + 1)):
        for j in range(3 * box_x, 3 * (box_x + 1)):
            if bo[i][j] == candida and not (i == row and j == col):
                return False

    return True

def next_empty(bo):
    for i in range(9):
        for j in range(9):
            if bo[i][j] == 0:
                return i, j
    return -1, -1

board = []

for i in range(9):
    row = [int(x) for x in input().split(' ')]
    board.append(row)

solve(board)
for i in range(9):
    row = ''
    for j in range(9):
        row += str(board[i][j]) + ' '
    print(row)