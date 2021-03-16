import sys
input = sys.stdin.readline

N,M,K = map(int, input().split())
board = []
god_str = ''
cnt = 0
dir = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]

def dfs(x, y, depth):
    global cnt

    if depth + 1 == len(god_str):
        cnt += 1
        return

    for dx, dy in dir:
        dir_x = (x + dx) % N
        dir_y = (y + dy) % M
        if god_str[depth+1] != board[dir_x][dir_y]: continue
        dfs(dir_x, dir_y, depth + 1)

for _ in range(N):
    board.append(input())

for _ in range(K):
    cnt = 0
    god_str = input().rstrip()
    for i in range(N):
        for j in range(M):
            if god_str[0] != board[i][j]: continue
            dfs(i, j, 0)
    print(cnt)