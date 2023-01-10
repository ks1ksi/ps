#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool visited[1001];
int N;
vector<set<int>> adj;

void dfs(int cur, vector<int> &ret) {
    visited[cur] = true;
    ret.push_back(cur);
    if (ret.size() == 4) return;

    for (auto next : adj[cur]) {
        if (!visited[next]) dfs(next, ret);
    }

    if (ret.size() < 4) ret.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    adj.resize(N+1);

    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace(b);
        adj[b].emplace(a);
    }

    vector<vector<int>> ans;
    
    int idx = 1;
    while (idx <= N) {
        vector<int> ret;

        memset(visited, 0, sizeof(visited));
        dfs(idx, ret);
        
        if (ret.size() == 4) {
            ans.push_back(ret);
            adj[ret[0]].erase(ret[1]);
            adj[ret[1]].erase(ret[2]);
            adj[ret[2]].erase(ret[3]);

            adj[ret[1]].erase(ret[0]);
            adj[ret[2]].erase(ret[1]);
            adj[ret[3]].erase(ret[2]);

            adj[ret[0]].emplace(ret[2]);
            adj[ret[0]].emplace(ret[3]);
            adj[ret[1]].emplace(ret[3]);

            adj[ret[2]].emplace(ret[0]);
            adj[ret[3]].emplace(ret[0]);
            adj[ret[3]].emplace(ret[1]);
        }
        else {
            idx++;
        }
    }
    
    cout << ans.size() << '\n';
    for (auto &v : ans) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}