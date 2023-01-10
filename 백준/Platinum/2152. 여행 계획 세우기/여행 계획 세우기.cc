#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 10001;
int N, M, S, T, cnt, scnt;
int discovered[MAX], sccn[MAX];
bool finished[MAX];
vector<vector<int>> adj, scc;
stack<int> s;

int dfs (int cur) {
    s.push(cur);
    discovered[cur] = ++cnt;
    int ret = discovered[cur];
    for (int next : adj[cur]) {
        if (!discovered[next]) {
            ret = min(ret, dfs(next));
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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> S >> T;
    adj = vector<vector<int>>(N+1);
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i < N+1; i++) {
        if (!discovered[i]) dfs(i);
    }

    vector<vector<int>> sccadj(scc.size());
    vector<int> indegree(scc.size(), 0);

    for (int i = 1; i < N+1; i++) {
        for (int next : adj[i]) {
            if (sccn[i] != sccn[next]) {
                sccadj[sccn[i]].push_back(sccn[next]);
                indegree[sccn[next]]++;
            }
        }
    }

    int start = sccn[S];
    int end = sccn[T];
    vector<int> count(scc.size());
    queue<int> q;

    for (int i = 0; i < scc.size(); i++) {
        if (!indegree[i]) q.push(i);
    }

    for (int i = 0; i < scc.size(); i++) {
        count[i] = scc[i].size();
    }

    vector<int> can(scc.size());
    can[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == end) break;
        for (int next : sccadj[cur]) {
            if (can[cur]) {
                count[next] = max(count[next], count[cur]+(int)scc[next].size());
                can[next] = true;
            }
            if (!--indegree[next]) q.push(next);
        }
    }
    
    if (can[end]) cout << count[end] << '\n';
    else cout << 0 << '\n';

    return 0;
}