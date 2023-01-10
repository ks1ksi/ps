N = int(input())
t = []

for i in range(N):
    l = list(map(int, input().split()))
    t.append(l)

ans = [[] for _ in range(N)]
ans[0] = t[0]

for i in range(1, len(t)):
    for j in range(len(t[i])):
        # 양 끝의 경우
        if j == 0:
            ans[i].append(ans[i - 1][0] + t[i][j])
        elif j == i:
            ans[i].append(ans[i - 1][i - 1] + t[i][j])
        else:
            ans[i].append(max(ans[i - 1][j - 1], ans[i - 1][j]) + t[i][j])

print(max(ans[N - 1]))
