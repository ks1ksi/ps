#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int N;
int arr[20][20];
int cache[1<<20];

int solve(int worker, int cur) {
    if (cur == (1<<N)-1) return 0;
    
    int& ret = cache[cur];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i = 0; i < N; i++) {
        if (cur&(1<<i)) continue;
        ret = min(ret, solve(worker+1, cur|(1<<i)) + arr[worker][i]);
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
    memset(cache, -1, sizeof(cache));
    cout << solve(0, 0);
    return 0;
}