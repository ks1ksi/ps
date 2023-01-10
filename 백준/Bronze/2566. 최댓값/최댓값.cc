#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int MAX = 10001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m = 0, r = 1, c = 1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int x;
            cin >> x;
            if (x > m) {
                m = x;
                r = i+1;
                c = j+1;
            }
        }
    }

    cout << m << '\n' << r << ' ' << c << '\n';

    return 0;
}