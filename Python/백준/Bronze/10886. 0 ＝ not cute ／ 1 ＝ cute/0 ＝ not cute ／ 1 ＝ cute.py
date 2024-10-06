n = int(input())
a = b = 0
for _ in range(n):
    x = int(input())
    if x == 1:
        a += 1
    else:
        b += 1

if a > b:
    print('Junhee is cute!')
else:
    print('Junhee is not cute!')
