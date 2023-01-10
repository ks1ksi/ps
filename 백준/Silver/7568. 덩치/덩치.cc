#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& [a, b] : v) {
        cin >> a >> b;
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        auto [a, b] = v[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto [c, d] = v[j];
            if (a < c && b < d) cnt++;
        }
        ans[i] = cnt+1;
    }

    for (auto x : ans) {
        cout << x << ' ';
    }

    return 0;
}