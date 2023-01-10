#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, k;
vector<int> v, t;
bool check[360];

void solve(int cur) {
    check[cur] = true;
    for (int i = 0; i < 2*n; i++) {
        int next = cur + v[i];
        next %= 360;
        if (next < 0 || check[next]) continue;
        solve(next);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.emplace_back(x);
        v.emplace_back(-x);
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        t.emplace_back(x);
    }

    solve(0);

    // for (int i = 0; i < 360; i++) {
    //     if (check[i]) cout << i << ' ';
    // }
    // cout << '\n';

    for (int i = 0; i < k; i++) {
        if (check[t[i]]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}