import sys
input = sys.stdin.readline

str1 = input().rstrip()
str2 = input().rstrip()

dp = [[0] * 1001 for _ in range(1001)]
m = 0
idx = (0, 0)

for i in range(1, len(str1)+1):
    for j in range(1, len(str2)+1):
        if str1[i-1] == str2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
            if dp[i][j] > m:
                m = dp[i][j]
                idx = (i, j)
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])

print(m)
if m > 0:
    r, c = idx
    ans = []
    for y in range(r, 0, -1):  # str1
        for x in range(c, 0, -1):  # str2
            if str1[y-1] == str2[x-1] and dp[y][x] == m:
                ans.insert(0, str2[x-1])
                m -= 1
                c = x - 1
                break
    print(''.join(ans))
