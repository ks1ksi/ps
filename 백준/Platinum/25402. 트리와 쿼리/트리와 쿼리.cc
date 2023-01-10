#include <bits/stdc++.h>

using namespace std;

const int MAX = 250005;
int N, Q;
int p[MAX], tp[MAX];
bool can[MAX], visited[MAX];
vector<vector<int>> adj;

int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void Union(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    p[n1] += p[n2];
    p[n2] = n1;
}

void dfs(int cur, int prev) {
    visited[cur] = true;
    tp[cur] = prev;
    for (auto& next : adj[cur]) {
        if (!visited[next]) dfs(next, cur);
    }
}

long long solve(vector<int>& v) {
    long long ans = 0;
    for (auto& x : v) {
        if (can[tp[x]]) Union(x, tp[x]);
    }
    for (auto& x : v) {
        int n = find(x);
        if (p[n] < -1) {
            ans += 1LL*(-p[n])*(-p[n]-1)/2;
            p[n] = -1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    adj.resize(N+1);

    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    // for (int i = 1; i < N+1; i++) {
    //     cout << tp[i] << ' ';
    // }
    // cout << '\n';

    cin >> Q;

    while (Q--) {
        int k;
        vector<int> v;

        memset(p, -1, sizeof(p));
        memset(can, 0, sizeof(can));

        cin >> k;        
        while (k--) {
            int x;
            cin >> x;
            can[x] = true;
            v.push_back(x);
        }

        cout << solve(v) << '\n';
    }

    return 0;
}