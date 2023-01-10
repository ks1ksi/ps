#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 32001;
int N, M;
vector<vector<int>> adj;
int indegree[MAX];
vector<int> ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    adj = vector<vector<int>>(N+1);
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i < N+1; i++) {
        if (!indegree[i]) pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        ans.push_back(cur);
        for (int next : adj[cur]) {
            if (!(--indegree[next])) {
                pq.push(next);
            }
        }
    }
    
    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}