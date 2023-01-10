#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // S = 2, K = -1
    string s;
    cin >> s;
    vector<int> v(s.size()+1), cnt(s.size()+1);
    map<int, int> minidx;
    for (int i = 0; i < s.size(); i++) {
        int n = 0;
        if (s[i] == 'S') n = 2;
        if (s[i] == 'K') n = -1;
        v[i+1] = v[i] + n;
        cnt[i+1] = cnt[i] + (n == 0 ? 0 : 1);
    }

    int ans = -1;

    for (int i = 0; i < s.size()+1; i++) {
        if (minidx.find(v[i]) == minidx.end()) {
            minidx[v[i]] = i;
        }
        else {
            int midx = minidx[v[i]];
            if (cnt[midx] == cnt[i]) continue;
            ans = max(ans, i-midx);
        }
    }

    cout << ans;

    // for (auto x : v) {
    //     cout << x << ' ';
    // }
    // cout << '\n';
    // for (auto p : minidx) {
    //     cout << p.first << p.second << '\n';
    // }

    return 0;
}