n, m = map(int, input().split())
visited = [False] * n
ans = []

def dfs(dep):
    if dep == m:
        print(' '.join(ans))
        return
    for num in range(n):
        if not visited[num]:
            ans.append(str(num + 1))
            visited[num] = True
            dfs(dep + 1)
            ans.pop()
            visited[num] = False

dfs(0)
