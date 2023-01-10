#include <bits/stdc++.h>

using namespace std;

int N;
int dp[101][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j > 0) {
                dp[i][j] += dp[i-1][j-1]%1000000000;
            }
            if (j < 9) {
                dp[i][j] += dp[i-1][j+1]%1000000000;
            }
        }
    }
    
    long long ans = 0;
    
    for (int i = 0; i < 10; i++) {
        ans += dp[N][i]%1000000000;
    }
    
    cout << ans%1000000000;
    
    return 0;
}