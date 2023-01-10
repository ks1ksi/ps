#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(3);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int s = 0;
        for (auto& x : v) {
            cin >> x;
            s += x;
        }
        ld avg = (ld) s / n;
        int cnt = 0;
        for (auto x : v) {
            if (x > avg) cnt++;
        }
        cout << (ld) cnt / n * 100 << "%\n";
    }

    return 0;
}