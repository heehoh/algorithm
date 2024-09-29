T = int(input())
for _ in range(T):
    num = int(input())
    mx = 0
    mxS = ''
    for _ in range(num):
        li = input().split()
        if mx < int(li[1]):
            mx = int(li[1])
            mxS = li[0]
            
    print(mxS)