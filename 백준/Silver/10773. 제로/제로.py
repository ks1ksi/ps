N = int(input())
nList = []
for i in range(N):
    num = int(input())
    if num != 0:
        nList.append(num)
    else:
        nList.pop()
print(sum(nList))
