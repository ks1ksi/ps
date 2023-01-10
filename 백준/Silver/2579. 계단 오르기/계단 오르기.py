import sys
input = sys.stdin.readline

N = int(input())
stairList = [int(input()) for _ in range(N)]
dp = [0]*N

dp[0] = stairList[0]
if N > 1:
    dp[1] = stairList[0] + stairList[1]
if N > 2:
    dp[2] = max(stairList[0], stairList[1]) + stairList[2]
if N > 3:
    for i in range(3, N):
        dp[i] = max(dp[i - 3] + stairList[i - 1] + stairList[i], dp[i - 2] + stairList[i])

print(dp[N - 1])
