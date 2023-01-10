#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int d[2000][2000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            d[i][j] = x - '0';
        }
    }

    int ans = 0;
    for (int j = 0; j < m-1; j++) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            x = max(x, d[i][j]);
        }
        ans += x;
    }

    cout << ans;

    return 0;
}