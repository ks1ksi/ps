#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr ll MOD = 1234567891;

ll modpow(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1) {
        return (a * modpow(a, b - 1)) % MOD;
    }
    ll c = modpow(a, b / 2);
    return (c * c) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;

    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a' + 1;
        ans += x * modpow(31, i);
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}