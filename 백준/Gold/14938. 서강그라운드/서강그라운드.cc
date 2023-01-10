#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, r;
int items[100], dist[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }

    while (r--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a-1][b-1] = c;
        dist[b-1][a-1] = c;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!dist[i][j]) dist[i][j] = 1e9;
            if (i == j) dist[i][j] = 0;
        }
    }
    
    // i -> j vs i ->k -> j
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= m) x += items[j];
        }
        ans = max(ans, x);
    }

    cout << ans << '\n';

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}