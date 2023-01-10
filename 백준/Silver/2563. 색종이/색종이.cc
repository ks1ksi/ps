#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool arr[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                arr[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (arr[i][j]) ans++;
        }
    }

    cout << ans;

    return 0;
}