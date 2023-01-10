#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2500], cache[2500][2][2];

int solve(int cur, int two, int cnt) {
    if (cur == N-1) {
        if (cnt) return 1;
        return 0;
    }

    int& ret = cache[cur][two][bool(cnt)];
    if (ret != -1) return ret;

    ret = 1e9;

    if (cnt) {
        if (arr[cur+1] >= cnt) {
            ret = min(ret, solve(cur+1, 1, arr[cur+1] - cnt) + 1);
        }
        ret = min(ret, solve(cur+1, 0, arr[cur+1]) + 1);        

    }

    else {
        ret = min(ret, solve(cur+1, 0, arr[cur+1]));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    memset(cache, -1, sizeof(cache));
    cout << solve(0, 0, arr[0]) << '\n';

    return 0;
}