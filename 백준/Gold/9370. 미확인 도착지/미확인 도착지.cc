#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, t, s, g, h, gh;
        cin >> n >> m >> t >> s >> g >> h;
        vector<vector<pair<int, int>>> adj(n+1); // d, next 
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].emplace_back(d, b);
            adj[b].emplace_back(d, a);
            if (a == g && b == h || a == h && b == g) gh = d;
        }
        vector<int> dest(t);
        for (auto& x : dest) {
            cin >> x;
        }

        auto dijkstra = [&](int start, int end, int dist[]) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, node
            fill(dist, dist+2001, 1e9);
            dist[start] = 0;
            pq.emplace(0, start);
            while (pq.size()) {
                auto [cost, cur] = pq.top();
                pq.pop();
                if (dist[cur] < cost) continue;
                for (auto [nc, next] : adj[cur]) {
                    if (dist[cur] + nc < dist[next]) {
                        dist[next] = dist[cur] + nc;
                        pq.emplace(dist[next], next);
                    }
                }
            }
            return dist[end];
        };

        // s -> x 최단거리
        // s -> g -> h -> x / s -> h -> g -> x 최단거리
        set<int> ans;
        for (auto x : dest) {
            int dist[2001];
            int total = dijkstra(s, x, dist);
            int sghx = dist[g] + gh;
            int shgx = dist[h] + gh;
            sghx += dijkstra(h, x, dist);
            shgx += dijkstra(g, x, dist);
            if (total == sghx || total == shgx) {
                ans.emplace(x);
            }
        }
        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}