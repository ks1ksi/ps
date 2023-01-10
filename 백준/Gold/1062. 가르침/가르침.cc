#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int ans = 0;
vector<int> v;

void solve(int cur, int cnt, int idx) {
    if (cnt == k) {
        int can = 0;
        for (auto x : v) {
            if (((cur^x)&x) == 0) can++;
        }
        ans = max(ans, can);
        return;
    }

    for (int i = idx+1; i < 26; i++) {
        if (cur&(1<<i)) continue;
        solve(cur|(1<<i), cnt+1, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = 0;
        for (auto c : s) {
            x = x|(1<<(c-'a'));
        }
        v.push_back(x);
    }

    if (k < 5) {
        cout << 0 << '\n';
        return 0;
    }

    int start = 0;
    string s = "antic";
    for (auto c : s) {
        start = start|(1<<(c-'a'));
    }
    solve(start, 5, 0);

    cout << ans << '\n';

    return 0;
}