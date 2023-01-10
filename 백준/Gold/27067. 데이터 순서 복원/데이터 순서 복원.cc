#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(3, vector<int>(n));

    for (auto& vec : v) {
        for (auto& x : vec) {
            cin >> x;
        }
    }

    // <단계, <인덱스, 개수>>
    map<int, map<int, int>> mp;

    for (auto& vec : v) {
        for (int i = 0; i < n; i++) {
            mp[vec[i]][i]++;
        }
    }

    int mcnt = 0;
    for (auto& [x, mmp] : mp) {
        mcnt = max(mcnt, (int)mmp.size());
    }

    vector<int> ans(n);

    // 어떤 단계가 서로 다른 3개의 인덱스에 존재하는 경우
    // 그 중간값이 원래 인덱스이다.
    // 하나 위치 확정시키고, 그 단계가 원래보다 앞에 가 있는 벡터를 찾아서 순서를 복원한다.
    if (mcnt == 3) {
        int idx, item;
        for (auto& [x, mmp] : mp) {
            if (mmp.size() == 3) {
                idx = next(mmp.begin(), 1)->first;
                item = x;
                break;
            }
        }

        for (auto& vec : v) {
            if (find(vec.begin(), vec.end(), item) - vec.begin() < idx) {
                int i = 0, j = 0;
                while (j != n) {
                    if (vec[i] == item) {
                        i++;
                    }
                    else if (j == idx) {
                        ans[j] = item;
                        j++;
                    }
                    else {
                        ans[j] = vec[i];
                        i++;
                        j++;
                    }
                }
            }
        }
    }

    // 서로 다른 3개의 인덱스에 존재하는 단계가 없는 경우
    // 모든 단계는 제자리에 위치하는 경우가 항상 2개 이상 존재한다.
    else {
        for (auto& [x, mmp] : mp) {
            int idx = mmp.begin()->second >= 2 ? mmp.begin()->first : next(mmp.begin(), 1)->first;
            ans[idx] = x;
        }
    }

    for (auto x : ans) {
        cout << x << ' ';
    }

    return 0;
}