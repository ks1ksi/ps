#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 200005;
const ll MOD[2] = {100000007, 1000000009};
const int BASE = 107;

ll power[MAX][2];
ll psum[MAX][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    power[0][0] = power[0][1] = 1;
    psum[0][0] = psum[0][1] = s[0];

    for (int i = 1; i <= s.size(); i++) {
        for (int k = 0; k < 2; k++) {
            power[i][k] = power[i-1][k]*BASE%MOD[k];
            psum[i][k] = (psum[i-1][k]*BASE+s[i])%MOD[k];
        }
    }

    int lo = 1, hi = s.size(), mid;
    int ans = -1;
    unordered_map<ll, int> um;

    while (lo <= hi) {
        bool found = false;
        mid = (lo + hi)/2;
        ll h0 = psum[mid-1][0];
        ll h1 = psum[mid-1][1];
        um.clear();
        um.insert({(h0<<32)|h1, mid-1});
        for (int i = 1; i <= s.size()-mid; i++) {
            h0 = h0 - s[i-1]*power[mid-1][0]%MOD[0] + MOD[0];
            h0 = (h0*BASE+s[i+mid-1])%MOD[0];
            h1 = h1 - s[i-1]*power[mid-1][1]%MOD[1] + MOD[1];
            h1 = (h1*BASE+s[i+mid-1])%MOD[1];

            ll key = (h0<<32)|h1;
            if (um.find(key) != um.end() && um[key] < i) {
                found = true;
                ans = max(ans, mid);
                break;
            }
            else um.insert({key, i+mid-1});
        }
        if (found) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << ans;

    return 0;
}
