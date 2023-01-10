N, K = map(int, input().split())
value = [int(input()) for _ in range(N)]

d1 = [1] + [0]*K
d2 = [1] + [0]*K

for i in range(1, K + 1):
    if i % value[0] == 0:
        d1[i] = 1

value.pop(0)

for v in value:
    for i in range(1, K + 1):
        if i < v:
            d2[i] = d1[i]
        else:
            d2[i] = d1[i] + d2[i - v]
    d1 = d2

print(d1[K])