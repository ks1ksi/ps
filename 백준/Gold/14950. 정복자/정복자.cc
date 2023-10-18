#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, m, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    vector<vector<pair<int, int>>> edge(n + 1); // cost, dest;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(c, b);
        edge[b].emplace_back(c, a);
    }

    // for (auto &vec : edge) {
    //     for (auto [x, y] : vec) {
    //         cout << x << ' ' << y << '\n';
    //     }
    // }

    int cnt = 1, visited[10001] = {0}, ans = 0;
    visited[1] = 1;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>> // cost, a, b
        pq;

    for (auto &[c, b] : edge[1]) {
        pq.emplace(c, 1, b);
    }

    while (!pq.empty()) {
        auto [cost, cur, next] = pq.top();
        pq.pop();
        if (visited[next])
            continue;

        visited[next] = 1;
        ans += (cnt++ - 1) * t + cost;

        // cout << next << ' ' << cost << ' ' << ans << '\n';

        for (auto &[c, n] : edge[next]) {
            pq.emplace(c, next, n);
        }
    }

    cout << ans << '\n';

    return 0;
}