#include <bits/stdc++.h>

using namespace std;

#define int long long

int H, Q, R;
double diff[100003], sum[100003];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cout << fixed;
    cout.precision(5);

    cin >> H >> Q >> R;

    vector<int> v;
    for (int i = 1; i <= H; i++) {
        v.push_back(i*(i+1)/2);
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        int h = lower_bound(v.begin(), v.end(), a) - v.begin() + 1;
        int sz = H-h+2;
        int d = h*(h+1)/2 - a;
        int r = H - d + 1;
        int l = r - sz + 1;
        double s = 1.0*b/sz;
        diff[l] += s;
        diff[r+1] -= s;
    }

    double total = 0;
    for (int i = 1; i <= H+1; i++) {
        total += diff[i];
        sum[i] = sum[i-1] + total;
    }

    while (R--) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }

    return 0;
}