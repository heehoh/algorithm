from collections import deque

M, N, K = map(int, input().split())
visited = [[False] * N for _ in range(M)]
for _ in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            visited[i][j] = True

ans = []
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
            
def BFS(x, y):
    q = deque()
    q.append((x, y))
    visited[y][x] = True
    size = 1
    
    while q:
        cur_x, cur_y = q.popleft()
        for i in range(4):
            pos_x = cur_x + dx[i]
            pos_y = cur_y + dy[i]
            if 0 <= pos_x < N and 0 <= pos_y < M:
                if not visited[pos_y][pos_x]:
                    size += 1
                    visited[pos_y][pos_x] = True
                    q.append((pos_x, pos_y))
    
    ans.append(size)
    
for i in range(M):
    for j in range(N):
        if not visited[i][j]:
            BFS(j, i)

ans.sort()
print(len(ans))
for a in ans:
    print(a, end=' ')