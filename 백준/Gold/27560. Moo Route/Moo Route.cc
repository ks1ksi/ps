#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    
    // 오른쪽 넘어가는거 방지
    v.emplace_back(0);

    vector<char> ans;
    int cur = 0;
    while (v[0]) {
        // 오른쪽
        if (cur == 0 || v[cur-1] < v[cur]) {
            v[cur]--;
            cur++;
            ans.emplace_back('R');
        }

        // 왼쪽
        else {
            cur--;
            v[cur]--;
            ans.emplace_back('L');
        }
    }

    for (auto c : ans) {
        cout << c;
    }

    return 0;
}