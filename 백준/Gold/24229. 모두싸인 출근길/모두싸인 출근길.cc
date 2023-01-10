#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int N, cache[200000];
vector<pair<int, int>> v;

int solve(int cur) {
    int& ret = cache[cur];
    if (ret != -1) return ret;
    ret = v[cur].second;
    
    int i = 0, cnt = v[cur].second - v[cur].first;
    while (++i) {
        if (cur + i >= v.size() || v[cur + i].first > v[cur].second + cnt) break;
        ret = max(ret, solve(cur + i));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<pair<int, int>> tmp(N);
    for (auto& [a, b] : tmp) {
        cin >> a >> b;
    }

    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < N; i++) {
        if (v.size() && v[v.size()-1].second >= tmp[i].first) {
            v[v.size()-1].second = max(v[v.size()-1].second, tmp[i].second);
        }
        else v.emplace_back(tmp[i]);
    }

    // cout << '\n';
    // for (auto [a, b] : v) {
    //     cout << a << ' ' << b << '\n';
    // }

    memset(cache, -1, sizeof(cache));
    cout << solve(0);

    return 0;
}