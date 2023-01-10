#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> bcnt(20); // 각 자리수별로 1이 몇 개 있는지

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j]&(1<<i)) bcnt[i]++;
        }
    }

    ll ans = 0;

    for (int i = 0; i < 20; i++) {
        ans += (1LL<<i)*bcnt[i]*(n-bcnt[i]);
    }
    
    cout << ans;

    return 0;
}