N = int(input())
arr = list(map(int, input().split()))
d = [arr[0]] + [0]*(N - 1)

for i in range(1, N):
    if d[i - 1] < 0:
        d[i] = arr[i]
    else:
        d[i] = d[i - 1] + arr[i]

print(max(d))
