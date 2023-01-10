#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<vector<int>> v;
int n;

int solve() {
    int ret = 1e9;
    vector<int> tmp;
    for (int i = 0; i < n / 2; i++) {
        tmp.emplace_back(0);
    }
    for (int i = 0; i < n / 2; i++) {
        tmp.emplace_back(1);
    }

    do {
        vector<int> lv, sv;
        for (int i = 0; i < n; i++) {
            if (tmp[i]) lv.emplace_back(i);
            else sv.emplace_back(i);
        }

        int lk = 0, st = 0;
        for (auto i : lv) {
            for (auto j : lv) {
                lk += v[i][j];
            }
        }
        for (auto i : sv) {
            for (auto j : sv) {
                st += v[i][j];
            }
        }
        ret = min(ret, abs(lk - st));
    } while (next_permutation(tmp.begin(), tmp.end()));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    v.resize(n, vector<int>(n));

    for (auto& vec : v) {
        for(auto& x : vec) {
            cin >> x;
        }
    }

    cout << solve() << '\n';

    return 0;
}
