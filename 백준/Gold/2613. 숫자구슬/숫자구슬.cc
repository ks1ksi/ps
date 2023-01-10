#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    int lo = *max_element(v.begin(), v.end()), hi = 30000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int sum = 0, gcnt = 1;
        for (auto x : v) {
            if (sum + x > mid) {
                gcnt++;
                sum = x;
            }
            else sum += x;
        }
        if (gcnt > m) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << lo << '\n';

    int sum = 0, cnt = 0, as = 0;
    vector<int> ans;
    for (auto x : v) {
        if (sum + x > lo) {
            ans.push_back(cnt);
            as += cnt;
            sum = x;
            cnt = 1;
        }
        else {
            sum += x;
            cnt++;
        }
    }
    ans.push_back(n - as);

    int rem = m - ans.size();
    for (auto& x : ans) {
        while (rem && x > 1) {
            rem--;
            cout << 1 << ' ';
            x--;
        }
        cout << x << ' ';
    }

    return 0;
}