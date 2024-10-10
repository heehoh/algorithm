n, s = map(int, input().split())
arr = list(map(int, input().split()))
ans = []
cnt = 0

def recur(st):
    global cnt
    if sum(ans) == s and len(ans) > 0:
        cnt += 1
    
    for i in range(st, n):
        ans.append(arr[i])
        recur(i+1)
        ans.pop()
        
recur(0)
print(cnt)
