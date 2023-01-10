#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int m = INT_MAX, M = 0;
    while (n--) {
        int x;
        cin >> x;
        m = min(m, x);
        M = max(M, x);
    }
    cout << m*M;

    return 0;
}