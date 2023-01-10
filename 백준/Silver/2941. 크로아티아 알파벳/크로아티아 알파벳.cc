#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = s.size();

    vector<string> vs = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    for (auto& ts : vs) {
        int n = 0;
        while (1) {
            int next = s.find(ts, n);
            if (next == s.npos) break;;
            ans--;
            n = next + ts.size();
        }
    }

    cout << ans;

    return 0;
}