#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    vector<int> uv, dv, uvec(n), dvec(n);

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(uv.begin(), uv.end(), v[i]);
        if (it == uv.end()) {
            uv.emplace_back(v[i]);
            uvec[i] = uv.size();
        }
        else {
            *it = v[i];
            uvec[i] = it - uv.begin() + 1;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        auto it = lower_bound(dv.begin(), dv.end(), v[i]);
        if (it == dv.end()) {
            dv.emplace_back(v[i]);
            dvec[i] = dv.size();
        }
        else {
            *it = v[i];
            dvec[i] = it - dv.begin() + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, uvec[i] + dvec[i] - 1);
    }

    cout  << ans;

    return 0;
}
