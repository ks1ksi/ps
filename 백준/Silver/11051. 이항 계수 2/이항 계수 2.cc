#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int MOD = 10007;

int cache[1001][1001];

int solve(int n, int r) {
    if (r == 0 || n == r) return 1;

    int& ret = cache[n][r];
    if (ret != -1) return ret;

    return ret = (solve(n-1, r-1) + solve(n-1, r)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r;
    cin >> n >> r;
    memset(cache, -1, sizeof(cache));

    cout << solve(n ,r);
    
    return 0;
}