board = []
dots = [[], [], []]

def solve(x, y, z):
    board[x][y] = str(z)
    dots[k].append((x,y))
    if x - 1 >= 0 and board[x-1][y] == 'X':
        solve(x-1, y, z)

    if x + 1 < n and board[x+1][y] == 'X':
        solve(x+1, y, z)

    if y - 1 >= 0 and board[x][y-1] == 'X':
        solve(x, y-1, z)

    if y + 1 < m and board[x][y+1] == 'X':
        solve(x, y+1, z)


n, m = (int(x) for x in input().split(' '))
for i in range(n):
    board.append(list(input()))

k = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 'X':
            solve(i, j, k)
            k += 1

conns = []

for i in range(3):
    for j in range(i+1, 3):
        current_best = 10 ** 9

        for a in dots[i]:
            for b in dots[j]:
                dist = abs(a[0] - b[0]) + abs(a[1] - b[1]) - 1
                current_best = min(current_best, dist)
        
        conns.append(current_best)

print(min([conns[0] + conns[1], conns[0] + conns[2], conns[1] + conns[2]]))