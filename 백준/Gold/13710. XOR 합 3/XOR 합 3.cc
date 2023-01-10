#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i] = v[i-1]^x;
    }


    vector<int> bcnt(30); // 각 자리수별로 1이 몇 개 있는지

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j <= n; j++) {
            if (v[j]&(1<<i)) bcnt[i]++;
        }
    }

    ll ans = 0;

    for (int i = 0; i < 30; i++) {
        ans += (1LL<<i)*bcnt[i]*(n+1-bcnt[i]);
    }
    
    cout << ans;

    return 0;
}