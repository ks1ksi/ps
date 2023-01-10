#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 301;
int N, cnt, scnt;
int discovered[MAX], sccn[MAX];
bool finished[MAX];
stack<int> s;

int dfs (int cur, vector<vector<int>>& adj, vector<vector<int>>& scc) {
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
            sccn[t] = scnt;
            finished[t] = true;
            v.push_back(t);
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
        cin >> N;

        memset(discovered, 0, sizeof(discovered));
        memset(finished, 0, sizeof(finished));
        cnt = 0;
        scnt = 0;
        vector<vector<int>> adj(N+1), scc;

        for (int i = 1; i < N+1; i++) {
            for (int j = 1; j < N+1; j++) {
                char x;
                cin >> x;
                if (x == '1') adj[i].push_back(j);
            }
        }

        for (int i = 1; i < N+1; i++) {
            if (!discovered[i]) dfs(i, adj, scc);
        }

        vector<vector<bool>> sccadj(scc.size(), vector<bool>(scc.size()));
        for (int i = 1; i < N+1; i++) {
            for (int next : adj[i]) {
                if (sccn[i] != sccn[next]) {
                    sccadj[sccn[i]][sccn[next]] = true;
                }
            }
        }

        // 중복 제거
        for (int k = 0; k < scc.size(); k++) {
            for (int i = 0; i < scc.size(); i++) {
                for (int j = 0; j < scc.size(); j++) {
                    if (sccadj[i][k] && sccadj[k][j]) {
                        sccadj[i][j] = false;
                    }
                }
            }
        }

        vector<pair<int, int>> ans;
        // SCC별로 연결
        for (int i = 0; i < scc.size(); i++) {
            for (int j = 0; j < scc.size(); j++) {
                if (sccadj[i][j]) ans.push_back({scc[i][0], scc[j][0]});
            }
        }
        // SCC내 간선 최소한으로 출력 (사이클 하나 만들어서 출력)
        for (auto& v : scc) {
            if (v.size() > 1) {
                for (int i = 0; i < v.size()-1; i++) {
                    ans.push_back({v[i], v[i+1]});
                }
                ans.push_back({v[v.size()-1], v[0]});
            }
        }
        
        cout << ans.size() << '\n';
        for (auto& p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
        cout << '\n';

    }
    return 0;
}