#include <bits/stdc++.h>

using namespace std;

int N, M, K, MAX = 0;
int jew[101];
bool visited[101][1<<15];
vector<vector<pair<int, int>>> v(101);

void solve(int pos, int j) {
    visited[pos][j] = true;
    int jcnt = __builtin_popcount(j);
    if (pos == 1) {
        if (jew[1] && !(j&(1<<jew[1]))) jcnt++;
        MAX = max(MAX, jcnt);
    }
    
    for (auto p : v[pos]) {
        int next = p.first;
        int limit = p.second;
        if (!visited[next][j] && limit >= jcnt) {
            solve(next, j);
        }
        if (jew[pos] && !(j&(1<<jew[pos]))) {
            if (!visited[next][j|(1<<jew[pos])] && limit >= jcnt+1) {
                solve(next, j|(1<<jew[pos]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        jew[x] = i+1;    
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    solve(1, 0);
    cout << MAX;
    return 0;
}