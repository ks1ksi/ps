#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> dist(n);
    vector<pair<int, int>> cost(n);
    for (int i = 1; i < n; i++) {
        ll d;
        cin >> d;
        dist[i] = dist[i-1]+d;
    }
    // for (auto x : dist) {
    //     cout << x << ' ';
    // }
    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        cost[i] = {c, i};
    }
    sort(cost.begin(), cost.end());
    
    ll ans = 0;
    int last = n-1;
    for (auto p : cost) {
        if (p.second > last) continue;
        ans += (dist[last] - dist[p.second])*p.first;
        // cout << ans << ' ' << p.second << ' ' << last << '\n';
        last = p.second;
        if (last == 0) break;
    }
    cout << ans;


    return 0;
}