#include <bits/stdc++.h>

using namespace std;

int solve(int x) {
    int start = x/4*4;
    int ret = start;
    while (++start <= x) {
        ret ^= start;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (solve(a-1)^solve(b)) << '\n';
    }

    return 0;
}