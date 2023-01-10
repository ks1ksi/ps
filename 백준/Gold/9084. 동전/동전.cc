#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int dp[20][10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        vector<int> coins(n);
        for (auto& x : coins) {
            cin >> x;
        }
        cin >> m;

        memset(dp, 0, sizeof(dp));

        for (int j = 0; j <= m; j++) {
            if (j % coins[0] == 0) dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            int c = coins[i];
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= c) dp[i][j] += dp[i][j-c];
            }
        }

        cout << dp[n-1][m] << '\n';

    }

    return 0;
}