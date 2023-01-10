#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 501;
int N;
vector<vector<int>> adj;
int cost[MAX];
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

    cin >> N;
    adj = vector<vector<int>>(N+1);
    for (int i = 1; i < N+1; i++) {
        cin >> cost[i];
        int x;
        while (1) {
            cin >> x;
            if (x == -1) break;
            adj[x].push_back(i);
        }
    }

    for (int i = 1; i < N+1; i++) {
        if (!visited[i]) dfs(i);
    }

    int tc[N+1];
    for (int i = 1; i < N+1; i++) {
        tc[i] = cost[i];
    }
    for (auto x = ans.rbegin(); x != ans.rend(); x++) {
        for (int n : adj[*x]) {
            tc[n] = max(tc[n], cost[n]+tc[*x]);
        }
    }
    for (int i = 1; i < N+1; i++) {
        cout << tc[i] << '\n';
    }

    return 0;
}