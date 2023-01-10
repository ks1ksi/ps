#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    bool f = 0;
    for (int i = 1; i < n; i++) {
        int s = 0, t = i;
        while (t) {
            s += t % 10;
            t /= 10;
        }
        if (s + i == n) {
            cout << i;
            f = 1;
            break;
        }
    }

    if (!f) cout << 0;

    return 0;
}