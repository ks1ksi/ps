#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> dp;

    for (auto x : v) {
        auto iter = lower_bound(dp.begin(), dp.end(), x);
        if (iter == dp.end()) dp.push_back(x);
        else *iter = x;
    }

    cout << n-dp.size() << '\n';

    return 0;
}