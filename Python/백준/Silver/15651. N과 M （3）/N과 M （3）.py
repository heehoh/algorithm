n, m = map(int, input().split())
ans = []
def dfs(dep):
    if dep == m:
        print(' '.join(ans))
        return
    for i in range(n):
        ans.append(str(i+1))
        dfs(dep+1)
        ans.pop()
dfs(0)