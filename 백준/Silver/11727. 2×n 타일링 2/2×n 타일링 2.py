N = int(input())
if N > 2:
    dp = [1, 3] + [0]*(N - 2)
    for i in range(2, N):
        dp[i] = dp[i - 1] + dp[i - 2]*2
    print(dp[-1] % 10007)
else:
    dp = [1, 3]
    print(dp[N - 1])