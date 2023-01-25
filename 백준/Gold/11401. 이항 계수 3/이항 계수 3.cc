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

    ll n, k;
    cin >> n >> k;
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = modpow(fact[i], MOD-2) % MOD;
    }
    
    cout << fact[n] * inv[k] % MOD * inv[n-k] % MOD;

    return 0;
}