#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 10001;
int V, E, cnt, dfsn[MAX];
vector<int> adj[MAX];
vector<vector<int>> scc;
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
        vector<int> v;
        while (1) {
            v.push_back(s.top());
            finished[s.top()] = true;
            s.pop();
            if (*(v.end()-1) == cur) break;
        }
        sort(v.begin(), v.end());
        scc.push_back(v);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >>E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i < V+1; i++) {
        if (!finished[i]) dfs(i);
    }
    sort(scc.begin(), scc.end());
    cout << scc.size() << '\n';
    for (auto v : scc) {
        for (int x : v) {
            cout << x << ' ';
        }
        cout << -1 << '\n';
    }
    return 0;
}