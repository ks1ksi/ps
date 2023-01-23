#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int get_idx(deque<int> dq, int target) { // copy deque
    int idx = 0;
    while (dq.size()) {
        if (dq.front() == target) break;
        idx++;
        dq.pop_front();
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    deque<int> dq;
    vector<int> v(m);
    
    for (auto& x : v) {
        cin >> x;
    }
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int ans = 0;
    for (auto target : v) {
        int idx = get_idx(dq, target);
        if (idx <= dq.size() / 2) {
            while (dq.front() != target) {
                int tmp = dq.front();
                dq.pop_front();
                ans++;
                dq.push_back(tmp);
            }
            dq.pop_front();
        }
        else {
            while (dq.front() != target) {
                int tmp = dq.back();
                dq.pop_back();
                ans++;
                dq.push_front(tmp);
            }
            dq.pop_front();
        }
    }
    
    cout << ans;

    return 0;
}