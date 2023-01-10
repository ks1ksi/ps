#include <bits/stdc++.h>

using namespace std;

#define int long long

constexpr int MAX = 5001;
int N, arr[MAX], cache[MAX][MAX];

int solve(int cur, int next) {
    if (cur == N) return 0;

    int& ret = cache[cur][next];
    if (ret != -1) return ret;

    ret = LLONG_MAX;
    for (int i = cur+1; i < N+1; i++) {
        int nc = (i-cur)*(1+abs(arr[i]-arr[cur]));
        ret = min(ret, max(nc, solve(i, next)));
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i < N+1; i++) {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));

    cout << solve(1, N);

    return 0;
}