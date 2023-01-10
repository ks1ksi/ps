#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, b, a;
    cin >> n >> b >> a;
    
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < a; i++) {
        if (b < v[i]/2) {
            cout << cnt;
            return 0;
        }
        b -= v[i]/2;
        cnt++;
    }

    int start = 0;
    for (int i = a; i < n; i++) {
        if (b - v[start]/2 < v[i]/2) break;
        b -= (v[start]/2 + v[i]/2);
        cnt++;
        start++;
    }
    cout << cnt;

    return 0;
}