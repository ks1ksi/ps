//  연산자 끼워넣기

#include<bits/stdc++.h>

using namespace std;

vector<int> v, ops(4);
int n, max_value = -1e9, min_value = 1e9;

void solve(int idx, int cur) {
    if (idx == n) {
        max_value = max(max_value, cur);
        min_value = min(min_value, cur);
        return;
    }

    if (ops[0]) {
        ops[0]--;
        solve(idx+ 1 , cur + v[idx]);
        ops[0]++;
    }
    if (ops[1]) {
        ops[1]--;
        solve(idx+ 1 , cur - v[idx]);
        ops[1]++;
    }
    if (ops[2]) {
        ops[2]--;
        solve(idx+ 1 , cur * v[idx]);
        ops[2]++;
    }
    if (ops[3]) {
        ops[3]--;
        solve(idx+ 1 , cur / v[idx]);
        ops[3]++;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n);

    for (auto& x : v) {
        cin >> x;
    }

    for (auto& x : ops) {
        cin >> x;
    }

    solve(1, v[0]);

    cout << max_value << '\n' << min_value << '\n';

    return 0;
}
