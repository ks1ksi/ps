import sys
input = sys.stdin.readline

str1 = input().rstrip()
str2 = input().rstrip()
str3 = input().rstrip()

dp = [[[0] * 101 for _ in range(101)] for _ in range(101)]
m = 0

for i in range(1, len(str1)+1):
    for j in range(1, len(str2)+1):
        for k in range(1, len(str3)+1):
            if str1[i-1] == str2[j-1] == str3[k-1]:
                dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                m = max(m, dp[i][j][k])
            else:
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])

print(m)
