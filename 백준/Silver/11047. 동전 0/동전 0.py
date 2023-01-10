N, K = map(int, input().split())
value = [int(input()) for _ in range(N)]
cnt = 0
value.reverse()
for i in value:
    if i > K:
        continue
    else:
        cnt += K // i
        K %= i
print(cnt)