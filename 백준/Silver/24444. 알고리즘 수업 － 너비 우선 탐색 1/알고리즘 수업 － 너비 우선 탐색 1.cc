#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

// struct Compare {
//     bool operator() (const int a, const int b) const {
//         return a > b;
//     }
// };

int cnt = 1;
vector<set<int>> adj;
int visited[100001];

void bfs(int start) {
    queue<int> q;
    q.emplace(start);
    visited[start] = cnt++;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (auto next : adj[cur]) {
            if (visited[next]) continue;
            visited[next] = cnt++;
            q.emplace(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;
    adj.resize(n+1);
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace(b);
        adj[b].emplace(a);
    }

    bfs(start);
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}