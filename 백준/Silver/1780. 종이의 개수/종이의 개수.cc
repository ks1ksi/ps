#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int m1, z, p1, arr[2500][2500];

void solve(int y, int x, int sz) {
    int a = 0, b = 0, c = 0;
    for (int i = y; i < y + sz; i++) {
        for (int j = x; j < x + sz; j++) {
            if (arr[i][j] == -1) a++;
            else if (arr[i][j] == 0) b++;
            else c++;
        }
    }

    if (a && !b && !c) m1++;
    else if (!a && b && !c) z++;
    else if (!a && !b && c) p1++;
    else {
        if (sz == 1) return;
        int seg = sz / 3;
        solve(y, x, seg);
        solve(y + seg, x, seg);
        solve(y + 2*seg, x, seg);
        solve(y, x + seg, seg);
        solve(y + seg, x + seg, seg);
        solve(y + 2*seg, x + seg, seg);
        solve(y, x + 2*seg, seg);
        solve(y + seg, x + 2*seg, seg);
        solve(y + 2*seg, x + 2*seg, seg);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    solve(0, 0, n);

    cout << m1 << '\n' << z << '\n' << p1 << '\n';

    return 0;
}