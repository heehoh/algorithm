from collections import deque

N = int(input())
map_ = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
ans = 1
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def BFS(x, y, h):
    q = deque()
    q.append((x, y))
    visited[y][x] = True
    
    while q:
        curX, curY = q.popleft()
        for i in range(4):
            nxtX = curX + dx[i]
            nxtY = curY + dy[i]
            if 0 <= nxtX < N and 0 <= nxtY < N:
                if map_[nxtY][nxtX] > h and not visited[nxtY][nxtX]:
                    visited[nxtY][nxtX] = True
                    q.append((nxtX, nxtY))

def count_area(h):
    global ans
    for i in range(N):
        for j in range(N):
            visited[i][j] = False
            
    num = 0
    for i in range(N):
        for j in range(N):
            if map_[i][j] > h and not visited[i][j]:
                BFS(j, i, h)
                num += 1
    
    if num > ans:
        ans = num
        
mxH = max(max(row) for row in map_)
for h in range(1, mxH):
    count_area(h)
    
print(ans)
