#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1001;
int N, M;
vector<vector<int>> adj;
bool visited[MAX], finished[MAX];
stack<int> s;
bool cycle = false;

void dfs(int v) {
    visited[v] = true;
    for (int next : adj[v]) {
        if (!visited[next]) dfs(next);
        else if (!finished[next]) {
            cycle = true;
            break;
        }
    }
    s.push(v);
    finished[v] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    adj = vector<vector<int>>(N+1);
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        vector<int> v(n+1, 0);
        for (int i = 1; i < n+1; i++) {
            cin >> v[i];
            adj[v[i-1]].push_back(v[i]);
        }
    }

    for (int i = 1; i < N+1; i++) {
        if (!visited[i]) dfs(i);
    }
    if (cycle) cout << 0 << '\n';
    else {
        while(!s.empty()) {
            cout << s.top() << '\n';
            s.pop();
        }
    }

    return 0;
}