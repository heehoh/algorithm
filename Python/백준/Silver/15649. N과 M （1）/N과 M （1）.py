n, m = map(int, input().split())
visited = [False] * n
ans = []
def dfs(i):
    if m == i:
        print(' '.join(ans))
        return
    for j in range(n):
        if visited[j] == False:
            ans.append(str(j+1))
            visited[j] = True
            dfs(i+1)
            ans.pop()
            visited[j] = False

dfs(0)