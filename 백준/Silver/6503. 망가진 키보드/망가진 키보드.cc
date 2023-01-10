#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int count_char(int cmap[]) {
    int ret = 0;
    for (int i = 0; i < 150; i++) {
        if (cmap[i]) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    while (1) {
        cin >> m;
        if (m == 0) break;
        cin.ignore();
        string s;
        getline(cin, s);

        int cmap[150] = {0};

        int l = 0, r = 0;
        cmap[s[l]]++;

        int ans = 0;
        while (r < s.size()) {
            int sz = count_char(cmap);
            if (l > r) {
                r++;
                cmap[s[r]]++;
            }
            else if (sz <= m) {
                ans = max(ans, r-l+1);
                r++;
                cmap[s[r]]++;
            }
            else if (sz > m) {
                cmap[s[l]]--;
                l++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}