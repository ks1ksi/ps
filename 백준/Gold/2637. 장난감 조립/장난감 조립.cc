#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 101;
int N, M;
int indegree[MAX], tc[MAX][MAX];
bool b[MAX];
vector<vector<pair<int, int>>> adj;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    adj = vector<vector<pair<int, int>>>(N+1);
    while (M--) {
        int x, y, k;
        cin >> x >> y >> k;
        adj[y].push_back({x, k}); // k개의 x가 필요하다.
        indegree[x]++;
    }

    queue<int> q;
    for (int i = 1; i < N+1; i++) {
        if (!indegree[i]) {
            q.push(i);
            b[i] = true;
            tc[i][i] = 1;
        } 
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto p : adj[cur]) {
            for (int i = 1; i < N+1; i++) {
                tc[i][p.first] += tc[i][cur]*p.second;
            }
            if (!(--indegree[p.first])) {
                q.push(p.first);
            }
        }
    }

    for (int i = 1; i < N+1; i++) {
        if (tc[i][N] && b[i]) {
            cout << i << ' ' << tc[i][N] << '\n';
        }
    }

    return 0;
}