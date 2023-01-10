#include <bits/stdc++.h>

using namespace std;

int N;
int cache[1000001];

int solve(int cur) {
    if (cur == 1) {
        return 0;
    }

    int& ret = cache[cur];
    if (ret != -1) return ret;

    ret = 987654321;
    if (cur%3 == 0) {
        ret = min(ret, solve(cur/3) + 1);
    }
    if (cur%2 == 0) {
        ret = min(ret,solve(cur/2) + 1);
    }
    if (cur-1 > 0) {
        ret = min(ret, solve(cur-1) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    memset(cache, -1, sizeof(cache));
    int ans = solve(N);
    cout << ans << '\n';

    cache[1] = 0;
    while (N != 1) {
        cout << N << ' ';
        if (N%3 == 0 && cache[N/3] == ans-1) {
            N /= 3;
            ans--;
        }
        else if (N%2 == 0 && cache[N/2] == ans-1) {
            N /= 2;
            ans--;
        }
        else if (cache[N-1] == ans-1) {
            N--;
            ans--;
        }
    }
    cout << 1;

    // for (int i = 1; i <= N; i++) {
    //     cout << cache[i] << ' ';
    // }

    return 0;
}