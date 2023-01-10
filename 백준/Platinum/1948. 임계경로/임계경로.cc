#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 10001;
int N, M, S, E;
vector<pair<int, int>> adj[MAX], reverse_adj[MAX];
int indegree[MAX], reverse_indegree[MAX], last[MAX];
bool visited[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        reverse_adj[b].push_back({a, c});
        indegree[b]++;
        reverse_indegree[a]++;
    }
    cin >> S >> E;

    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto p : adj[cur]) {
            int next = p.first;
            int cost = last[cur]+p.second;
            last[next] = max(last[next], cost);
            if (!--indegree[next]) q.push(next);
        }
    }

    // for (int i = 1; i < N+1; i++) {
    //     cout << last[i] << ' ';
    // }
    // cout << '\n';

    int ans = 0;

    q.push(E);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto p : reverse_adj[cur]) {
            int next = p.first;
            int nc = p.second;
            if (!visited[cur][next] && last[cur]-last[next] == nc) {
                visited[cur][next] = true;
                q.push(next);
                ans++;
            }
        }
    }

    cout << last[E] << '\n' << ans << '\n';
    
    return 0;
}