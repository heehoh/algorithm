from collections import deque

N = int(input())
map_ = [list(input()) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def BFS(x, y, c):
    q = deque()
    q.append((x, y))
    visited[y][x] = True
    
    while q:
        curX, curY = q.popleft()
        for i in range(4):
            nx = curX + dx[i]
            ny = curY + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if map_[ny][nx] == c and not visited[ny][nx]:
                    visited[ny][nx] = True
                    q.append((nx, ny))

num1 = 0
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            BFS(j, i, map_[i][j])
            num1 += 1

for i in range(N):
    for j in range(N):
        visited[i][j] = False
        if map_[i][j] == 'G':
            map_[i][j] = 'R'

num2 = 0
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            BFS(j, i, map_[i][j])
            num2 += 1
       
    
print(num1, num2)

