from collections import deque

n, k = map(int, input().split())
visited = [-1] * 100001
q = deque()
q.append((n,0))
visited[n] = n

def check(x, t, cur):
    if 0 <= x <= 100000 and visited[x] == -1:
        q.append((x, t))
        visited[x] = cur

while q:
    cur, t = q.popleft()
    if cur == k:
        print(t)
        path = []
        while cur != n:
            path.append(cur)
            cur = visited[cur]
        path.append(cur)
        print(*path[::-1])
        
    check(cur+1, t+1, cur)
    check(cur-1, t+1, cur)
    check(cur*2, t+1, cur)