N = int(input())
nList = []
for i in range(N):
    age, name = input().split()
    age = int(age)
    nList.append([age, i, name])

nList.sort()

for a in nList:
    print("{} {}".format(a[0], a[2]))

