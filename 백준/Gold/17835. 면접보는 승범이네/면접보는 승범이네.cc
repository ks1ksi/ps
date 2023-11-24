#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);  // cost, next
    vector<int> mv(k);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 길을 반대로 넣어준다
        adj[b].emplace_back(c, a);
    }

    for (auto& x : mv) {
        cin >> x;
    }

    vector<ll> dist(n + 1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq;

    fill(dist.begin(), dist.end(), 1e18);

    // 면접장까지 거리 0으로 설정
    // 길 반대로 넣고 모든 면접장에서 출발한다고 가정하고 풀기
    for (auto& x : mv) {
        pq.emplace(0, x);
        dist[x] = 0;
    }

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        if (dist[cur] < cost) continue;
        for (auto& [c, n] : adj[cur]) {
            if (dist[n] > cost + c) {
                dist[n] = cost + c;
                pq.emplace(dist[n], n);
            }
        }
    }

    ll idx = 0, d = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] > d) {
            d = dist[i];
            idx = i;
        }
    }

    cout << idx << '\n' << d << '\n';

    return 0;
}
