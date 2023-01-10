#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto& num : v) {
        cin >> num;
    }

    int cur = 0;
    while (1) {
        if (v[cur] < x) {
            cout << cur+1 << '\n';
            break;
        }
        cur++;
        x++;
        if (cur == n) cur = 0;
    }

    return 0;
}