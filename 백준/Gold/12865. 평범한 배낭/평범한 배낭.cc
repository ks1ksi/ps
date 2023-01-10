#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vec(n);
    for (auto& x : vec) {
        int a, b;
        cin >> a >> b;
        x = {a, b};
    }

    int ans = 0;
    for (auto x : vec) {
        auto [w, v] = x;
        for (int j = 0; j <= k-w; j++) {
            dp[j] = max(dp[j], dp[j+w] + v);
            ans = max(ans, dp[j]);
        }
    }

    cout << ans << '\n';

    return 0;
}