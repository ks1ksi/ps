#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    int curx = 1000, cury = 1000;
    int lm = 1000, rm = 1000, um = 1000, dm = 1000;

    set<pair<int, int>> st;
    for (int i = 0; i < 6; i++) {
        int d, l;
        cin >> d >> l;
        if (d == 1) {
            curx += l;
        }
        else if (d == 2) {
            curx -= l;
        }
        else if (d == 3) {
            cury += l;
        }
        else if (d == 4) {
            cury -= l;
        }
        st.emplace(curx, cury);
        lm = min(lm, curx);
        rm = max(rm, curx);
        um = max(um, cury);
        dm = min(dm, cury);
    }

    int t = (rm - lm) * (um - dm);

    pair<int, int> mp;
    for (auto p : st) {
        if (lm < p.first && p.first < rm && dm < p.second && p.second < um) {
            mp = p;
        }
    }
    auto [x, y] = mp;

    // cout << lm << ' ' << rm << ' ' << um << ' ' << dm << '\n';
    // cout << x << ' ' << y << '\n';

    int total;
    if (st.find({lm, dm}) == st.end()) {
        total = t - (x - lm) * (y - dm);
    }
    else if (st.find({lm, um}) == st.end()) {
        total = t - (x - lm) * (um - y);
    }
    else if (st.find({rm, dm}) == st.end()) {
        total = t - (rm - x) * (y - dm);
    }
    else {
        total = t - (rm - x) * (um - y);
    }

    // cout << t << ' ' << total << ' ' << total*k;
    cout << total*k;

    return 0;
}