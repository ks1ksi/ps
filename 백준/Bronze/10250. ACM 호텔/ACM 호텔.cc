#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int h, w, n;
        cin >> h >> w >> n;
        int f = n % h;
        if (!f) f = h;
        int s = ceil(1.0*n / h);
        cout << f;
        if (s < 10) cout << 0;
        cout << s << '\n';
    }

    return 0;
}