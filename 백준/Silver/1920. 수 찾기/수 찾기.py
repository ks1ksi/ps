N = int(input())
nList = list(map(int, input().split()))
M = int(input())
mList = list(map(int, input().split()))

for i in mList:
    if i in nList:
        print(1)
    else:
        print(0)
