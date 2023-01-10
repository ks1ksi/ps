#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    vector<ll> v = {1, 1, 1, 2, 2, 3};

    for (int i = 6; i <= 100; i++) {
        v.emplace_back(v[i-1] + v[i-5]);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << v[n-1] << '\n';
    }

    return 0;
}
