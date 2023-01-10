#include <bits/stdc++.h>

#define int long long

using namespace std;

int N, K;

signed main() {

    cin >> K >> N;
    vector<int> v(K);
    for (int i = 0; i < K; i++) {
        cin >> v[i];
    }

    int lo = 1, hi = INT_MAX;

    while (lo <= hi) {
        int mid = (hi + lo)/2;
        int cnt = 0;
        for (auto x : v) {
            cnt += x / mid;
        }
        if (cnt >= N) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << hi << '\n';

    return 0;
}