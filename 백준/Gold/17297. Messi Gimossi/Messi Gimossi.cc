#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m;
    cin >> m;

    vector<ll> messi = {5, 13};
    
    for (int i = 2; i < 50; i++) {
        ll next = messi[i-1] + messi[i-2] + 1;
        messi.emplace_back(next);
    }

    int idx = lower_bound(messi.begin(), messi.end(), m) - messi.begin();

    while (idx != 0 && idx != 1) {
        if (m <= messi[idx-1]) {
            idx--;
        }
        else if (m == messi[idx-1] + 1) {
            cout << "Messi Messi Gimossi\n";
            return 0;
        }
        else {
            m -= (messi[idx-1] + 1);
            idx -= 2;
        }
    }

    string s = "Messi Gimossi";
    m--;
    char c = s[m];
    if (c == ' ') cout << "Messi Messi Gimossi\n";
    else cout << c << '\n';

    return 0;
}