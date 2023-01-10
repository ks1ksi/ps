#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        bool graph[n+1][n+1] = {0};
        int indegree[n+1] = {0};
        vector<int> rank(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            cin >> rank[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                graph[rank[i]][rank[j]] = true;
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            swap(graph[a][b], graph[b][a]);
        }
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (graph[i][j]) indegree[j]++;
            }
        }

        for (int i = 1; i < n+1; i++) {
            if (!indegree[i]) q.push(i);
        }

        vector<int> final_rank;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            final_rank.push_back(cur);
            for (int i = 1; i < n+1; i++) {
                if (graph[cur][i] && !(--indegree[i])) {
                    q.push(i);
                }
            }
        }
        if (final_rank.size() != n) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            for (int x : final_rank) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}