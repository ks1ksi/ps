#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    if (s2.size() > s1.size()) swap(s1, s2);

    int zcnt = s1.size() - s2.size();
    string z;
    for (int i = 0; i < zcnt; i++) {
        z += "0";
    }
    s2 = z + s2;

    int cr = 0;
    string ans;
    for (int i = s1.size()-1; i >= 0; i--) {
        int x = cr + (s1[i] - '0') + (s2[i] - '0');
        ans += (char) (x%10 + '0');
        cr = x / 10;
    }
    if (cr) ans += (char) (cr + '0');
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    return 0;
}