t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    def GCD(a, b):
        while b > 0:
            a, b = b, a % b
        return a
    print((a*b) // GCD(a,b))
    
