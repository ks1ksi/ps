#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int k = 0, p = 0; // 마지막에 k, p로 끝난 개구리 몇마리?
    int ans = 1;
    if (s[0] == 'K') k++;
    else p++;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'K') {
            k++;
            if (p) p--;
        }
        else {
            p++;
            if (k) k--;
        }
        ans = max(ans, max(k, p));
        // cout << k << ' ' << p << ' ' << ans << '\n';
    }
    cout << ans;
    return 0;
}