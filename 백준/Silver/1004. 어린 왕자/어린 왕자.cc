#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ld dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2, n;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            if (dist(cx, cy, x1, y1) < r ^ dist(cx, cy, x2, y2) < r) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}