#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = 15001;
bool dp[30][30005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    cin >> m;
    vector<int> cv(m);
    for (auto& x : cv) {
        cin >> x;
    }
    
    dp[0][MAX+v[0]] = 1;
    dp[0][MAX-v[0]] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][MAX+v[i]] = 1;
        dp[i][MAX-v[i]] = 1;
        for (int j = 0; j <= 30003; j++) {
            dp[i][j] += dp[i-1][j];
            if (j >= v[i]) {
                dp[i][j-v[i]] += dp[i-1][j];
                dp[i][j] += dp[i-1][j-v[i]];
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = MAX; j < MAX+11; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (auto x : cv) {
        if (x >= MAX) cout << "N ";
        else if (dp[n-1][x+MAX]) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}