n = int(input())
x1, y1, x2, y2 = map(int, input().split())
print(2 * (x2 - x1 + y2 - y1))

for _ in range(n - 1):
    tx1, ty1, tx2, ty2 = map(int, input().split())
    x1, y1 = min(x1, tx1), min(y1, ty1)
    x2, y2 = max(x2, tx2), max(y2, ty2)
    print(2 * (x2 - x1 + y2 - y1))