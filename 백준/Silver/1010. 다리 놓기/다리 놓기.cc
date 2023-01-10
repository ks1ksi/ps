#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll cache[1001][1001];

ll solve(int n, int r) {
    if (r == 0 || n == r) return 1;

    ll& ret = cache[n][r];
    if (ret != -1) return ret;

    return ret = solve(n-1, r-1) + solve(n-1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    memset(cache, -1, sizeof(cache));
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << solve(m, n) << '\n';
    }
    
    return 0;
}