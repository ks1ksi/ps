#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 100003;
const int MAX = 200000;
int pow2[MAX+1];

int hashing(const char* c, int sz) {
    int ret = 0;
    for (int i = 0; i < sz; i++) {
        ret *= 2;
        ret %= MOD;
        ret += *(c+i);
    }
    return ret % MOD;
}

bool cmp(const char* i, const char* j, int sz) {
    bool flag = true;
    for (int k = 0; k < sz; k++) {
        if (*(i+k) != *(j+k)) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    pow2[0] = 1;
    for (int i = 1; i < n; i++) {
        pow2[i] = pow2[i-1]*2%MOD;
    }

    int ans = 0;
    int lo = 1, hi = n-1;
    while (lo <= hi) {
        bool found = false;
        vector<int> table[100003];
        int sz = (lo + hi)/2;
        int h = hashing(&s[0], sz);

        for (int i = 0; i <= n-sz; i++) {
            if (found) break;
            if (i != 0) {
                h = (h - s[i-1]*pow2[sz-1]%MOD + MOD)*2%MOD;
                h = (h + s[i+sz-1])%MOD;
            }
            if (table[h].size() > 0) {
                for (int pos : table[h]) {
                    if (cmp(&s[i], &s[pos], sz)) {
                        found = true;
                        ans = max(ans, sz);
                        break;
                    }
                }
            }
            table[h].push_back(i);
        }
        if (found) lo = sz+1;
        else hi = sz-1;
    }

    cout << ans;

    return 0;
}