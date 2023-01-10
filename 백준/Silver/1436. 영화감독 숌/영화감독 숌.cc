#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    for (int i = 0; i < 10000000; i++) {
        int scnt = 0, t = i;
        while (t) {
            if (t % 10 == 6) scnt++;
            else scnt = 0;
            if (scnt >= 3) {
                v.emplace_back(i);
                break;
            }
            t /= 10;
        }
    }

    int n;
    cin >> n;
    cout << v[n-1];

    return 0;
}