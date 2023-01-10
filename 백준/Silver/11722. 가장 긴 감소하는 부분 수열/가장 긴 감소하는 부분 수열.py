N = int(input())
arr = list(map(int, input().split()))
arr.insert(0, 987654321)
d = [0]*(N + 1)

for i in range(1, N + 1):
    tmp = 0
    for j in range(i):
        if tmp < d[j] and arr[j] > arr[i]:
            tmp = d[j]
    d[i] = tmp + 1

print(max(d))