#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int x = (i%2) ? -1 : 1;
        ret += (n/i)*x;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s, t;
    cin >> s >> t;
    cout << solve(t) - solve(s-1) << '\n';

    return 0;
}