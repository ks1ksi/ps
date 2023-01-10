#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1000000;
int N;
int cache[MAX+1][2];
bool visited[MAX+1];
vector<vector<int>> adj(MAX+1), tree(MAX+1);

void dfs(int node) {
    visited[node] = 1;
    for (int x : adj[node]) {
        if (!visited[x]) {
            tree[node].push_back(x);
            dfs(x);
        }
    }
}

int solve(int cur, bool adopter) { // 현재 노드, 부모가 얼리어답터인지
    int& ret = cache[cur][adopter];
    if (ret != -1) return ret;

    ret = MAX;
    int sum;

    if (adopter) { // 부모가 얼리어답터면 현재 노드를 고르지 않아도 됨
        sum = 0;
        for (int x : tree[cur]) {
            sum += solve(x, 0);
        }
        ret = min(ret, sum);
    }

    // 현재 노드를 얼리어답터로 고르는 경우
    sum = 1;
    for (int x : tree[cur]) {
        sum += solve(x, 1);
    }
    ret = min(ret, sum);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    memset(cache, -1, sizeof(cache));
    cout << solve(1, 1);
    return 0;
}