#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
    }

    int s, e, dist[1001], p[1001];
    cin >> s >> e;
    for (int i = 0; i <= 1000; i++) {
        dist[i] = 1e9;
        p[i] = -1;
    }
    dist[s] = 0;
    
    // cost, node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto [nc, next] : adj[cur]) {
            if (dist[next] > dist[cur] + nc) {
                dist[next] = dist[cur] + nc;
                pq.emplace(dist[next], next);
                p[next] = cur;
            }
        }
    }

    vector<int> ans;
    int pt = e;
    while (pt != -1) {
        ans.emplace_back(pt);
        pt = p[pt];
    }

    cout << dist[e] << '\n' << ans.size() << '\n';
    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }

    return 0;
}