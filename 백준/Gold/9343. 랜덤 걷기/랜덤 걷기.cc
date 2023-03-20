#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 4e6;
ll fact[MAX+1], inv[MAX+1];

ll modpow(ll a, ll b) {
    if (!b) return 1;
    ll mp = modpow(a, b/2);
    ll ret = mp*mp%MOD;
    if (b%2) return ret*a%MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv[MAX] = modpow(fact[MAX], MOD-2);
    for (int i = MAX-1; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % MOD;
    }

    int m;
    cin >> m;
    while (m--) {
        ll n;
        cin >> n;
        cout << fact[2*n] * inv[n] % MOD * inv[n+1] % MOD << '\n';
    }

    return 0;
}