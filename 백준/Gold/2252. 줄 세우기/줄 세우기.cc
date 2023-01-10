#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 32001;
int N, M;
vector<vector<int>> adj;
bool visited[MAX];
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int next : adj[v]) {
        if (!visited[next]) dfs(next);
    }
    ans.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    adj = vector<vector<int>>(N+1);
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i < N+1; i++) {
        if (!visited[i]) dfs(i);
    }

    for (auto x = ans.rbegin(); x != ans.rend(); x++) {
        cout << *x << ' ';
    }

    return 0;
}