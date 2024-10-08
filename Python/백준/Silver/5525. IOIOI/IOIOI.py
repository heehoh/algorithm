n = int(input())
m = int(input())
s = input()

pos = cnt = res = 0

while pos < (m-1):
    if s[pos:pos+3] == 'IOI':
        cnt += 1
        pos += 2
        if cnt == n:
            res += 1
            cnt -= 1
    else:
        pos += 1
        cnt = 0

print(res)
