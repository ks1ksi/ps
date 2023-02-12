#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    vector<int> v(n+1), pv;
    for (int i = 2; i <= sqrt(n); i++) {
        if (!v[i]) {
            for (int j = i + i; j <= n; j += i) {
                v[j]++;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!v[i]) pv.emplace_back(i);
    }

    int l = 0, r = 0, s = pv[0], cnt = 0;
    while (r < pv.size() && l <= r) {
        if (s == n) {
            cnt++;
            r++;
            if (r != pv.size()) s += pv[r];
        }
        else if (s < n) {
            r++;
            if (r != pv.size()) s += pv[r];
        }
        else {
            s -= pv[l];
            l++;
        }
    }

    cout << cnt;

    return 0;
}