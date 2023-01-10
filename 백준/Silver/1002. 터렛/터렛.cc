#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) cout << -1 << '\n';
            else cout << 0 << '\n';
        }
        else if (dist == (r1+r2)*(r1+r2) || dist == (r1-r2)*(r1-r2)) {
            cout << 1 << '\n';
        }
        else if (dist > (r1+r2)*(r1+r2) || dist < (r1-r2)*(r1-r2)) {
            cout << 0 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }
    return 0;
}