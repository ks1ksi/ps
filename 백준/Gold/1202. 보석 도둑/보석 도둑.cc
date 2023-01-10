#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> jw(n);
    vector<int> bg(k);
    priority_queue<int> pq;

    for (auto& p : jw) {
        int m, v;
        cin >> m >> v;
        p = {m, v};
    }

    for (auto& c : bg) {
        cin >> c;
    }

    sort(jw.begin(), jw.end());
    sort(bg.begin(), bg.end());

    ll ans = 0;
    int idx = 0;
    for (auto c : bg) {
        for (; idx < jw.size(); idx++) {
            auto [m, v] = jw[idx];
            if (m > c) break;
            else pq.push(v);
        }
        if (pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }

    cout << ans << '\n';

    return 0;
}