#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i <= n; i++) {
        v[i] = v[i-1] + v[i-2];
    }

    cout << v[n] << ' ';
    if (n == 1 || n == 2) cout << 1;
    else cout << n - 2;

    return 0;
}
