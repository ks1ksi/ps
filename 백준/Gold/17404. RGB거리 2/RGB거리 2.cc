#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000][3];
int cache[4][1000];

int solve(int start, int rgb, int cur) {
    if (cur == N) {
        if (rgb == start) return -1;
        else return 0;
    }
    
    int& ret = cache[rgb][cur];
    if (ret != -1) return ret;
    
    ret = 10000000;
    for (int i = 0; i < 3; i++) {
        if (rgb == i) continue;
        int x = solve(start, i, cur+1);
        if (x != -1) {
            ret = min(ret, x + arr[cur][i]);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        memset(cache, -1, sizeof(cache));
        ans = min(ans, solve(i, i, 1) + arr[0][i]);
    }
    cout << ans;
    return 0;
}