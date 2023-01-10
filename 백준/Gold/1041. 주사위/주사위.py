import itertools

N = int(input())
numList = list(map(int, input().split()))

#except 05 14 23

list3 = [(0, 1, 2), (0, 1, 3), (0, 2, 4), (0, 3, 4), (1, 2, 5), (1, 3, 5), (2, 4, 5), (3, 4, 5)]
oldList2 = list(itertools.combinations(range(6), 2))
deleteSet2 = {(0, 5), (1, 4), (2, 3)}
list2 = [i for i in oldList2 if i not in deleteSet2]

min1 = min(numList)
min2 = 100
min3 = 150
for i in list2:
    tmp = numList[i[0]] + numList[i[1]]
    min2 = min(min2, tmp)
for i in list3:
    tmp = numList[i[0]] + numList[i[1]] + numList[i[2]]
    min3 = min(min3, tmp)

if N == 1:
    print(sum(numList) - max(numList))

else:
    ans = min3*4 + min2*(N - 2)*4 + min1*(N - 2)**2 + (N - 1)*(min2*4 + min1*(N - 2)*4)
    print(ans)