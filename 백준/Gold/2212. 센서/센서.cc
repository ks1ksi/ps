#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n), diff(n-1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n-1; i++) {
        diff[i] = v[i+1] - v[i];
    }
    sort(diff.begin(), diff.end());
    int ans = 0;
    for (int i = 0; i < n-k; i++) {
        ans += diff[i];
    }
    cout << ans;

    return 0;
}