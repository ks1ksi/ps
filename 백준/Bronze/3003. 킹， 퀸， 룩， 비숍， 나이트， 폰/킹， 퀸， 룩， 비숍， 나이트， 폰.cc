#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1 = {1, 1, 2, 2, 2, 8};
    vector<int> v2(6);
    for (auto& x : v2) {
        cin >> x;
    }
    for (int i = 0; i < 6; i++) {
        cout << v1[i] - v2[i] << ' ';
    }
    
    return 0;
}