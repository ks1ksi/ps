#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> mp;
    mp[a]++;
    mp[b]++;
    mp[c]++;

    if (mp.size() == 1) {
        cout << 10000 + a*1000 << '\n';
    }
    else if (mp.size() == 2) {
        for (auto [k, v] : mp) {
            if (v == 2) {
                cout << 1000 + k*100 << '\n';
            }
        }
    }
    else {
        cout << max(max(a, b), c)*100 << '\n';
    }

    return 0;
}