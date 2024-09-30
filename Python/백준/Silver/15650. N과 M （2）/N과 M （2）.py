n, m = map(int, input().split())
ans = []

def dfs(dep, r):
    if dep == m:
        print(' '.join(ans))
        return
    for num in range(r, n):
        ans.append(str(num + 1))
        dfs(dep+1, num+1)
        ans.pop()
        
dfs(0, 0)