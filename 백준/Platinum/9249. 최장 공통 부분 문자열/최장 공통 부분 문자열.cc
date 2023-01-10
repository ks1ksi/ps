#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 200005;
const ll MOD[2] = {100000007, 1000000009};
const int BASE = 107;

ll power[MAX][2];
ll psum1[MAX][2];
ll psum2[MAX][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    power[0][0] = power[0][1] = 1;
    psum1[0][0] = psum1[0][1] = s1[0];
    psum2[0][0] = psum2[0][1] = s2[0];

    for (int i = 1; i < MAX; i++) {
        for (int k = 0; k < 2; k++) {
            power[i][k] = power[i-1][k]*BASE%MOD[k];
        }
    }

    for (int i = 1; i <= s1.size(); i++) {
        for (int k = 0; k < 2; k++) {
            psum1[i][k] = (psum1[i-1][k]*BASE+s1[i])%MOD[k];
        }
    }
    for (int i = 1; i <= s2.size(); i++) {
        for (int k = 0; k < 2; k++) {
            psum2[i][k] = (psum2[i-1][k]*BASE+s2[i])%MOD[k];
        }
    }

    int lo = 1, hi = min(s1.size(), s2.size()), mid;
    int ans = 0, idx;
    unordered_set<ll> us;

    while (lo <= hi) {
        us.clear();
        bool found = false;
        mid = (lo + hi)/2;
        ll h0 = psum1[mid-1][0];
        ll h1 = psum1[mid-1][1];
        us.insert((h0<<32)|h1);
        for (int i = 1; i <= s1.size()-mid; i++) {
            h0 = h0 - s1[i-1]*power[mid-1][0]%MOD[0] + MOD[0];
            h0 = (h0*BASE+s1[i+mid-1])%MOD[0];
            h1 = h1 - s1[i-1]*power[mid-1][1]%MOD[1] + MOD[1];
            h1 = (h1*BASE+s1[i+mid-1])%MOD[1];
            ll key = (h0<<32)|h1;
            us.insert(key);
        }


        for (int i = 0; i <= s2.size()-mid; i++) {
            if (i == 0) {
                h0 = psum2[mid-1][0];
                h1 = psum2[mid-1][1];
            }
            else {
                h0 = h0 - s2[i-1]*power[mid-1][0]%MOD[0] + MOD[0];
                h0 = (h0*BASE+s2[i+mid-1])%MOD[0];
                h1 = h1 - s2[i-1]*power[mid-1][1]%MOD[1] + MOD[1];
                h1 = (h1*BASE+s2[i+mid-1])%MOD[1];
            }
            ll key = (h0<<32)|h1;
            if (us.find(key) != us.end()) {
                found = true;
                ans = max(ans, mid);
                idx = i;
                break;
            }
        }

        if (found) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << ans << '\n' << s2.substr(idx, ans);

    return 0;
}
