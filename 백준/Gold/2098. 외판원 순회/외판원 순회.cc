#include <bits/stdc++.h>

using namespace std;

int N;
int arr[16][16]; // from, to
int dp[16][1<<16]; // current city, visited city list
const int INF = 987654321;

int solve(int cur, int visited) {
    if (visited == (1<<N)-1) {
        return arr[cur][0] ? arr[cur][0] : INF;
    }
    
    int &ret = dp[cur][visited];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i = 0; i < N; i++) {
        if (visited&(1<<i) || arr[cur][i] == 0) continue;
        ret = min(ret, solve(i, visited|(1<<i)) + arr[cur][i]);
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
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1);   
    return 0;
}