#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9+7;

long long p(long long a, long long n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    long long x = p(a, n/2);
    if (n % 2) return x*x*a%MOD;
    else return x*x%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    long long ans = 0;

    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         int sz = i-j-1;
    //         long long res = p(2, sz)*(v[i]-v[j])%MOD;
    //         ans = (ans+res)%MOD;
    //     }
    // }

    for (int i = 0; i < n; i++) {
        ans += (p(2, i)*v[i] - p(2, n-1-i)*v[i]);
        ans %= MOD;
    }
    cout << ans;
    return 0;
}