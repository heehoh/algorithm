builds = []
for i in range(int(input())):
    builds.append(int(input()))

stack = []
res = 0
for b in builds:
    while stack and stack[-1] <= b:
        stack.pop()
    stack.append(b)
    res += len(stack)-1
    
print(res)