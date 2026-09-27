#include <bits/stdc++.h>

using namespace std;

// n번째까지 턴 최대 ? 
int solve(vector<int>& money, vector<int> dp, int n) {
    for (int i = 1; i < n; i++) {
        if (i < 2) {
            dp[i] = max(money[i], dp[i-1]);        
        } else {
            dp[i] = max(dp[i-2] + money[i], dp[i-1]);        
        }
    }
    return ranges::max(dp);
}

int solution(vector<int> money) {
    int n = money.size();
    vector<int> dp(n, 0);
    int answer = solve(money, dp, n);
    dp[0] = money[0];
    answer = max(answer, solve(money, dp, n-1));
    return answer;
}