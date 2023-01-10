#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct Compare {
    bool operator() (const pair<ll, ll>& p1, const pair<ll, ll>& p2) const {
        return make_pair(p1.second, p1.first) < make_pair(p2.second, p2.first);
    }
};

ll square(ll x) {
    return x*x;
}

ll powdist(pair<ll, ll> p1, pair<ll, ll> p2) {
    return square(p1.first - p2.first) + square(p1.second - p2.second);
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (auto& [a, b] : v) {
        cin >> a >> b;
    }
    sort(v.begin(), v.end());

    set<pair<ll, ll>, Compare> st;
    ll dist = powdist(v[0], v[1]);
    st.emplace(v[0]);
    st.emplace(v[1]);
    for (int i = 2, j = 0; i < n; i++) {
        while (j < i && square(v[i].first - v[j].first) >= dist) {
            st.erase(v[j++]);
        }

        ll d = sqrt(dist) + 5;
        auto start = st.lower_bound({-10000, v[i].second - d});
        auto end = st.upper_bound({10000, v[i].second + d});

        for (auto it = start; it != end; it++) {
            dist = min(dist, powdist(v[i], *it));
        }

        st.emplace(v[i]);
    }

    cout << dist;

    return 0;
}