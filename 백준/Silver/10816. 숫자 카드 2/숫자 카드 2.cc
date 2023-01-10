#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> mp;
    int n, m;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        mp[x]++;
    }
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << mp[x] << ' ';
    }


    return 0;
}