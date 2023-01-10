#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 5001;
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
        // sort(v.begin(), v.end());
        scc.push_back(v);
        scnt++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int n, m;
        cin >> n;
        if (!n) break;
        cin >> m;
        vector<vector<int>> adj(n+1), scc;
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        memset(discovered, 0, sizeof(discovered));
        memset(finished, 0, sizeof(finished));
        cnt = 0;
        scnt = 0;
        for (int i = 1; i < n+1; i++) {
            if (!discovered[i]) dfs(i, adj, scc);
        }

        vector<vector<int>> sccadj(scc.size());
        vector<int> outdegree(scc.size());
        for (int i = 1; i < n+1; i++) {
            for (int next : adj[i]) {
                if (sccn[i] != sccn[next]) {
                    sccadj[sccn[i]].push_back(sccn[next]);
                    outdegree[sccn[i]]++;
                }
            }
        }
        // for (int x : outdegree) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        vector<int> ans;
        for (int i = 0; i < scc.size(); i++) {
            if (!outdegree[i]) {
                for (int x : scc[i]) {
                    ans.push_back(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';

        // for (auto v : scc) {
        //     for (int x : v) {
        //         cout << x << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    return 0;
}