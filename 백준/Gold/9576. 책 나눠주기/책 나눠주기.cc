#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> v(m);
        set<int> used;

        for (auto& p : v) {
            int a, b;
            cin >> a >> b;
            p = {a, b};
        }

        sort(v.begin(), v.end(), cmp);

        // for (auto& [a, b] : v) {
        //     cout << a << ' ' << b << '\n';
        // }

        int ans = 0;
        for (auto& [a, b] : v) {
            for (int i = a; i <= b; i++) {
                if (used.find(i) != used.end()) continue;
                used.emplace(i);
                ans++;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}