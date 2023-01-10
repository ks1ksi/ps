#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<char, int>> v(n);

    for (auto& [a, b] : v) {
        cin >> a >> b;
    }

    map<pair<int, int>, vector<int>> m;
    map<char, pair<int, int>> mm;
    mm['N'] = {1, 0};
    mm['S'] = {-1, 0};
    mm['E'] = {0, 1};
    mm['W'] = {0, -1};

    int y = 0, x = 0, t = 0;
    for (auto& [a, b] : v) {
        auto& [dy, dx] = mm[a];
        for (int i = 0; i < b; i++) {
            y += dy;
            x += dx;
            m[{y, x}].emplace_back(++t);
        }
    }

    int lo = 0, hi = 1000000;
    while (lo <= hi) {
        int cnt = 0;
        int mid = (lo + hi) / 2;
        // cout << "MID=" << mid << '\n';
        for (auto& [p, v] : m) {
            for (int i = 0; i < v.size()-1; i++) {
                for (int j = i+1; j < v.size(); j++) {
                    if (v[j] - v[i] < mid) continue;
                    else {
                        // cout << p.first << ' ' << p.second << ' ' << v[i] << ' ' << v[j] << '\n';
                        cnt++;
                        i = j-1;
                        break;
                    }
                }
            }
        }
        if (cnt < k) hi = mid - 1;
        else lo = mid + 1;
    }

    cout << hi << '\n';

    // for (auto& [yx, st] : m) {
    //     cout << yx.first << ' ' << yx.second << ": ";
    //     for (auto x : st) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}