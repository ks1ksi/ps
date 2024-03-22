#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int cnt[10] = {0};

int total_cnt() {
    int ret = 0;
    for (int i = 1; i < 10; i++) {
        if (cnt[i] > 0) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    int l = 0, r = 1, ans = 0;
    cnt[v[l]]++;
    cnt[v[r]]++;

    while (r < n) {
        int total = total_cnt();

        if (total > 2) {
            cnt[v[l]]--;
            l++;
        }

        else {
            ans = max(ans, r - l + 1);  // 최대 과일 개수 업데이트
            r++;
            if (r < n) cnt[v[r]]++;
        }
    }

    cout << ans << '\n';

    return 0;
}
