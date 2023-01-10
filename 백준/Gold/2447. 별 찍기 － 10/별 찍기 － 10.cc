#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool arr[2187][2187];

void solve(int y, int x, int sz) {
    if (sz == 3) {
        for (int i = y; i < y+3; i++) {
            for (int j = x; j < x+3; j++) {
                if (i == y+1 && j == x+1) continue;
                arr[i][j] = 1;
            }
        }
        return;
    }

    int seg = sz / 3;

    solve(y, x, seg);
    solve(y+seg, x, seg);
    solve(y+seg*2, x, seg);
    
    solve(y, x+seg, seg);

    solve(y+seg*2, x+seg, seg);

    solve(y, x+seg*2, seg);
    solve(y+seg, x+seg*2, seg);
    solve(y+seg*2, x+seg*2, seg);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    solve(0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            if (arr[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}