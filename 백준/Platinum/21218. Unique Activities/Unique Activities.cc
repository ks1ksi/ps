#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 300005;
const ll MOD[2] = {100000007, 1000000009};
const ll BASE = 31;

ll power[MAX][2];
ll psum[MAX][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    power[0][0] = power[0][1] = 1;
    for (int i = 1; i < s.size(); i++) {
        for (int k = 0; k < 2; k++) {
            power[i][k] = power[i-1][k]*BASE%MOD[k];
        }
    }

    for (int i = 1; i <= s.size(); i++) {
        for (int k = 0; k < 2; k++) {
            psum[i][k] = (psum[i-1][k]*BASE+s[i-1])%MOD[k];
        }
    }

    int lo = 1, hi = s.size(), mid;
    unordered_map<ll, int> cntm, idxm;
    pair<int, int> ans;
    while (lo <= hi) {
        int idx = s.size(), sz;
        bool found = false;
        mid = (lo+hi)/2;
        cntm.clear();
        idxm.clear();
        ll h[2] = {psum[mid][0], psum[mid][1]};
        cntm[h[0]<<32|h[1]] = 1;
        idxm[h[0]<<32|h[1]] = 0;
        for (int i = 1; i <= s.size()-mid; i++) {
            for (int k = 0; k < 2; k++) {
                h[k] = h[k] - power[mid-1][k]*s[i-1]%MOD[k] + MOD[k];
                h[k] = (h[k]*BASE + s[i-1+mid])%MOD[k];
            }
            cntm[h[0]<<32|h[1]]++;
            idxm[h[0]<<32|h[1]] = i;
        }
        for (auto p : cntm) {
            ll hash = p.first;
            int cnt = p.second;
            if (cnt == 1 && idx > idxm[hash]) {
                found = true;
                idx = idxm[hash];
                sz = mid;
                ans.first = idx;
                ans.second = sz;
            }
        }
        if (found) hi = mid-1;
        else lo = mid+1;
    }

    cout << s.substr(ans.first, ans.second);

    return 0;
}
