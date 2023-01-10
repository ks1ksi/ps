#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 500;
int cache[MAX][MAX], file[MAX], psum[MAX+1];

int solve(int cur, int next) {
    if (cur == next) return 0;

    int& ret = cache[cur][next];
    if (ret != -1) return ret;

    ret = 987654321;
    for (int i = cur; i < next; i++) {
        ret = min(ret, solve(cur, i) + solve(i+1, next) + psum[next+1]-psum[cur]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> file[i];
            psum[i+1] = psum[i] + file[i];
        }
        memset(cache, -1, sizeof(cache));
        cout << solve(0, k-1) << '\n';
    }

    return 0;
}
