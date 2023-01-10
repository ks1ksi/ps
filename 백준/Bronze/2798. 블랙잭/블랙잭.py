from itertools import combinations
arr = []
N, M = map(int, input().split())
cards = list(map(int, input().split()))
com = list(combinations(cards, 3))

for i in com:
    if sum(i) <= M:
        arr.append(sum(i))

print(max(arr))
