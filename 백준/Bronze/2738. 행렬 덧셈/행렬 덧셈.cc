#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int MAX = 10001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ans[100][100] = {0};
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            ans[i][j] += x;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            ans[i][j] += x;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}