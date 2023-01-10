#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 100001;
int cnt, scnt;
int discovered[MAX], sccn[MAX];
bool finished[MAX];
stack<int> s;

int dfs(int cur, vector<vector<int>>& adj, vector<vector<int>>& scc) {
    s.push(cur);
    discovered[cur] = ++cnt;
    int ret = discovered[cur];
    for (int next : adj[cur]) {
        if (!discovered[next]) {
            ret = min(ret, dfs(next, adj, scc));
        }
        else if (!finished[next]) {
            ret = min(ret, discovered[next]);
        }
    }
    if (ret == discovered[cur]) {
        vector<int> v;
        while (1) {
            int t = s.top();
            s.pop();
            v.push_back(t);
            finished[t] = true;
            sccn[t] = scnt;
            if (t == cur) break;
        }
        scc.push_back(v);
        scnt++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n), scc;
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        memset(discovered, 0, sizeof(discovered));
        memset(finished, 0, sizeof(finished));
        cnt = 0;
        scnt = 0;
        for (int i = 0; i < n; i++) {
            if (!discovered[i]) dfs(i, adj, scc);
        }
        vector<int> indegree(scc.size());
        vector<vector<int>> sccadj(scc.size());
        for (int i = 0; i < n; i++) {
            for (int next : adj[i]) {
                if (sccn[i] != sccn[next]) {
                    sccadj[sccn[i]].push_back(sccn[next]);
                    indegree[sccn[next]]++;
                }
            }
        }
        int start = -1;
        bool sw = false;
        for (int i = 0; i < scc.size(); i++) {
            if (!indegree[i]) {
                if (start != -1) sw = true;
                start = i;
            }
        }
        if (sw) {
            cout << "Confused\n";
        }
        else {
            for (int i = 0; i < n; i++) {
                if (sccn[i] == start) cout << i << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}