import sys
input = sys.stdin.readline

# nCm = (n-1)C(m) + (n-1)C(m-1)

dp = [[0] * 101 for _ in range(101)]

for i in range(101):
    dp[i][0] = 1
    dp[i][i] = 1

for i in range(2, 101):
    for j in range(1 ,i):
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1]

n, m = map(int, input().split())
print(dp[n][m])
