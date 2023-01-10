#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 100001;
int V, E, cnt, scccnt, dfsn[MAX], sccn[MAX];
vector<vector<int>> adj, scc;
stack<int> s;
bool finished[MAX];

int dfs(int cur) {
    dfsn[cur] = ++cnt;
    s.push(cur);
    int ret = dfsn[cur]; // 자식중에 가장 높이 올라갈 수 있는거
    for (int next : adj[cur]) {
        if (!dfsn[next]) {
            ret = min(ret, dfs(next));
        }
        else if (!finished[next]) { // 아직 SCC 추출 안된거
            ret = min(ret, dfsn[next]);
        }
    }
    // 더이상 위로 올라갈 곳이 없으면
    if (ret == dfsn[cur]) {
        scccnt++;
        vector<int> v;
        while (1) {
            v.push_back(s.top());
            finished[s.top()] = true;
            sccn[s.top()] = scccnt;
            s.pop();
            if (*(v.end()-1) == cur) break;
        }
        scc.push_back(v);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E;
        vector<vector<int>> v(V+1);
        memset(dfsn, 0, sizeof(dfsn));
        memset(sccn, 0, sizeof(sccn));
        memset(finished, 0, sizeof(finished));
        adj = v;
        scc.clear();
        cnt = 0;
        scccnt = 0;

        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        for (int i = 1; i < V+1; i++) {
            if (!finished[i]) dfs(i);
        }

        vector<int> indegree(scccnt+1);

        for (int i = 1; i < V+1; i++) {
            for (int next : adj[i]) {
                if (sccn[i] != sccn[next]) indegree[sccn[next]]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < scccnt+1; i++) {
            if (!indegree[i]) ans++;
        }
        cout << ans << '\n';

    }



    return 0;
}