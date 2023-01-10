#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int N, M;
int mem[100];
int c[100];
int dp[100][10001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> mem[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    int ans = 10001;
    for (int i = c[0]; i < 10001; i++) {
        dp[0][i] = mem[0];
    }
    if (mem[0] >= M) ans = c[0];  
       
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10001; j++) {
            if (j < c[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]]+mem[i]);        
            }
            if (dp[i][j] >= M) {
                ans = min(ans, j);
            }
        }
    }
    
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < 20; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    cout << ans;
    return 0;
}