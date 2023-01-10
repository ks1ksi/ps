N = int(input())
nList = list(map(int, input().split()))
arr = [1]*2 + [0]*(999)

for i in range(2, 1001):
    if arr[i] == 0:
        idx = i + i
        while idx < 1001:
            arr[idx] = 1
            idx += i

ans = 0
for v in nList:
    if arr[v] == 0:
        ans += 1

print(ans)
