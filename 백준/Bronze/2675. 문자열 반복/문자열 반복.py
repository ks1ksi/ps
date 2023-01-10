T = int(input())
for _ in range(T):
    R, S = input().split()
    R = int(R)
    newS = ""
    for ch in S:
        newS += ch*R
    print(newS)
