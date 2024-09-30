from collections import deque

N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]
deg = [0] * (N + 1)

for _ in range(M):
    a, b = map(int, input().split())
    deg[b] += 1
    adj[a].append(b)

q = deque()

for i in range(1, N + 1):
    if deg[i] == 0:
        q.append(i)

while q:
    p = q.popleft()
    print(p, end=' ')
    for a in adj[p]:
        deg[a] -= 1
        if deg[a] == 0:
            q.append(a)