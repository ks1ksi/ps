#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    short arr[n+1][3] = {};
    int dp[n+1][3] = {};
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + arr[i][0];
        dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + arr[i][1];
        dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + arr[i][2];
    }
    
    int max_ans = 0;
    for (int i = 0; i < 3; i++) {
        max_ans = max(max_ans, dp[n][i]);
    }
    
    
    fill(&dp[1][0], &dp[n][2]+1, INT_MAX);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + arr[i][0];
        dp[i][1] = min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + arr[i][2];        
    }
    
    int min_ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        min_ans = min(min_ans, dp[n][i]);
    }
    
    cout << max_ans << ' ' << min_ans;
    return 0;
}