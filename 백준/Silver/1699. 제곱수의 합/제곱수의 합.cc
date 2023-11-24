#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int pn[320], cache[100001];

int solve(int cur) {
    if (cur == 0) {
        return 0;
    }

    if (cache[cur] != -1) return cache[cur];

    int& ret = cache[cur];
    ret = 1e9;

    for (int i = 1; i < 320; i++) {
        if (cur - pn[i] < 0) break;
        ret = min(ret, solve(cur - pn[i]) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < 320; i++) {
        pn[i] = i * i;
    }

    fill(cache, cache + sizeof(cache) / sizeof(int), -1);

    cout << solve(n) << '\n';

    return 0;
}
