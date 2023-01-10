#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> m;

    int lo = 1, hi = *max_element(v.begin(), v.end());
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int ans = 0;
        for (auto x : v) {
            if (x > mid) ans += mid;
            else ans += x;
        }
        if (ans <= m) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << hi << '\n';

    return 0;
}