#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 500001;
int N, M, S, P, cnt, scnt;
int money[MAX], discovered[MAX], sccn[MAX];
bool finished[MAX];
vector<int> sccmoney, maxmoney, rest, indegree;
vector<vector<int>> adj, scc, sccadj;
stack<int> s;


int dfs(int cur) {
    discovered[cur] = ++cnt;
    s.push(cur);
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
        int m = 0;
        while (1) {
            int t = s.top();
            s.pop();
            finished[t] = true;
            sccn[t] = scnt;
            m += money[t];
            v.push_back(t);
            if (t == cur) break;
        }
        // SCC 0번부터 시작
        scc.push_back(v);
        sccmoney.push_back(m);
        scnt++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    adj = vector<vector<int>>(N+1);
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i < N+1; i++) {
        cin >> money[i];
    }
    cin >> S >> P;
    while (P--) {
        int x;
        cin >> x;
        rest.push_back(x);
    }

    // SCC 만들기
    for (int i = 1; i < N+1; i++) {
        if (!discovered[i]) dfs(i);
    }

    sccadj = vector<vector<int>>(scc.size());
    indegree = vector<int>(scc.size());
    maxmoney = vector<int>(sccmoney.begin(), sccmoney.end());

    // 컴포넌트별로 연결
    for (int i = 1; i < N+1; i++) {
        for (int next : adj[i]) {
            if (sccn[i] != sccn[next]) {
                sccadj[sccn[i]].push_back(sccn[next]);
                indegree[sccn[next]]++;
            }
        }
    }

    // 주어진 시작 위치에서 도달 가능한지 확인하기 위해
    int sccstart = sccn[S];
    vector<bool> can(scc.size());
    can[sccstart] = true;

    // 위상정렬 하면서 최대 금액 찾기
    queue<int> q;
    for (int i = 0; i < scc.size(); i++) {
        if (!indegree[i]) q.push(i);
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : sccadj[cur]) {
            // 도달 가능한 경우 금액 갱신
            if (can[cur]) {
                maxmoney[next] = max(maxmoney[next], maxmoney[cur]+sccmoney[next]);
                can[next] = true;
            }
            if (!--indegree[next]) q.push(next);
        }
    }

    int ans = 0;
    for (int r : rest) {
        if (can[sccn[r]]) ans = max(ans, maxmoney[sccn[r]]);
    }
    cout << ans << '\n';

    return 0;
}