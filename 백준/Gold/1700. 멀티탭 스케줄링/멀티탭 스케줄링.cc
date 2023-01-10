#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    vector<int> v(K);
    for (int i = 0; i < K; i++) {
        cin >> v[i];
    }

    vector<int> cur;
    auto iter = v.begin();

    while (iter != v.end() && cur.size() != N) {
        if (find(cur.begin(), cur.end(), *iter) == cur.end()) {
            cur.push_back(*iter);
        }
        iter++;
    }

    int ans = 0;

    while (iter != v.end()) {
        if (find(cur.begin(), cur.end(), *iter) == cur.end()) {
            auto k = iter;
            int target = -1;
            for (int i = 0 ; i < N; i++) {
                auto nk = find(iter, v.end(), cur[i]);
                if (nk > k) {
                    k = nk;
                    target = i;
                }
            }
            cur[target] = *iter;
            ans++;
        }
        iter++;
    }

    cout << ans;

    return 0;
}