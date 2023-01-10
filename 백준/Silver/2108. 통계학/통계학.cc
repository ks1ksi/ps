#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    map<int, int> cntm;
    for (auto& x : v) {
        cin >> x;
        cntm[x]++;
        sum += x;
    }

    sort(v.begin(), v.end());

    int mcnt = 0;
    for (auto [x, cnt] : cntm) {
        mcnt = max(mcnt, cnt);
    }
    vector<int> cv;
    for (auto [x, cnt] : cntm) {
        if (cnt == mcnt) cv.emplace_back(x);
    }

    int ch = (cv.size() > 1) ? cv[1] : cv[0];

    cout << (int) round(1.0*sum / n) << '\n' << v[n/2] << '\n' << ch << '\n' << v[n-1] - v[0] << '\n';

    return 0;
}