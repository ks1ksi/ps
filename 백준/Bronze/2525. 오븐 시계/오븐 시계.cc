#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, m, d, x;
    cin >> h >> m >> d;
    x = h * 60 + m + d;

    if (x >= 1440) x -= 1440;

    cout << x / 60 << ' ' << x % 60 << '\n';

    return 0;
}