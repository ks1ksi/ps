#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(5);

    int n;
    cin >> n;
    int m = 0, s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m = max(m, x);
        s += x;
    }
    cout << (ld) s / n * 100 / m;

    return 0;
}