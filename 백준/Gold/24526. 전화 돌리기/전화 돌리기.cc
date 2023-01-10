#include <bits/stdc++.h>

using namespace std;

int N, M, indegree[100001];
vector<vector<int>> rev(100001);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        rev[b].push_back(a);
        indegree[a]++;
    }

    queue<int> q;
    for (int i = 1; i < N+1; i++) {
        if (!indegree[i]) q.push(i);
    }

    int ans = q.size();

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : rev[cur]) {
            if (!--indegree[next]) {
                q.push(next);
                ans++;
            }
        }
    }
    
    cout << ans;

    return 0;
}