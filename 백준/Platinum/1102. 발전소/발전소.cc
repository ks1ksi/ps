#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int N, P, start = 0, ans = INF;
int arr[16][16];
int cache[1<<16];

int solve(int visited) {
    int cnt = __builtin_popcount(visited);
    if (cnt >= P) {
        return 0;
    }
    
    int &ret = cache[visited];
    if (ret != -1) return ret;
    
    ret = INF;
    
    for (int i = 0; i < N; i++) { // start
        if (!(visited&(1<<i))) continue;
        for (int j = 0; j < N; j++) { // end
            if (visited&(1<<j)) continue;
            ret = min(ret, solve(visited|(1<<j)) + arr[i][j]);
        }
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    string s;
    cin >> s;
    for (int c = 0; c < s.size(); c++) {
        if (s[c] == 'Y') {
            start |= (1<<c);
        }
    }
    cin >> P;
    memset(cache, -1, sizeof(cache));
    ans = solve(start);
    if (P == 0) cout << 0;
    else if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}