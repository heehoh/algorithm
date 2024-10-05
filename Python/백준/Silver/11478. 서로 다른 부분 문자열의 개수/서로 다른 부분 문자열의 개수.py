s = set()
str_ = input()

for st in range(len(str_)):
    for en in range(st+1, len(str_) + 1):
        s.add(str_[st:en])

print(len(s))