import sys
input = sys.stdin.readline

T = int(input())
while T > 0:
    n = int(input())
    sticker = [list(map(int, input().split())) for _ in range(2)]
    dp = [[0] * n for _ in range(2)]

    dp[0][0] = sticker[0][0]
    dp[1][0] = sticker[1][0]
    
    if n > 1:
        dp[0][1] = sticker[1][0] + sticker[0][1]
        dp[1][1] = sticker[0][0] + sticker[1][1]

    if n > 2:
        for i in range(2, n):
            dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + sticker[0][i]
            dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + sticker[1][i]
            
    m1 = max(dp[0])
    m2 = max(dp[1])
    print(max(m1, m2))

    T -= 1
