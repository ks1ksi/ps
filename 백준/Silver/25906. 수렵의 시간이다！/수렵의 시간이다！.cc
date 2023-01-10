#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, k;
vector<vector<int>> skills(5);
vector<vector<pair<int, vector<int>>>> items(3);

int calculate(int money, pair<int, vector<int>> &item1, pair<int, vector<int>> &item2, pair<int, vector<int>> &item3) {
    int tc = item1.first + item2.first + item3.first;
    if (tc > money) return -1;

    int ret = 0;
    vector<int>lv(5);
    for (int i = 0; i < 5; i++) {
        lv[i] = item1.second[i] + item2.second[i] + item3.second[i];
        ret += skills[i][min((int)skills[i].size()-1, lv[i])];
    }

    if (money - k >= tc) {
        for (int i = 0; i < 5; i++) { // down
            if (!lv[i]) continue;
            lv[i]--;
            for (int j = 0; j < 5; j++) { // up
                if (i == j) continue;
                lv[j]++;
                int tmp = 0;
                for (int k = 0; k < 5; k++) {
                    tmp += skills[k][min((int)skills[k].size()-1, lv[k])];
                }
                ret = max(ret, tmp);
                lv[j]--;
            }
            lv[i]++;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> k;

    for (auto& v : skills) {
        int sz;
        cin >> sz;
        v.push_back(0);
        for (int i = 0; i < sz; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
    }
    
    for (auto& v : items) {
        int sz;
        cin >> sz;
        v.resize(sz+1);

        v[0].first = 0;
        for (int i = 0; i < 5; i++) {
            v[0].second.push_back(0);
        }

        for (int i = 1; i <= sz; i++) {
            cin >> v[i].first;
        }

        for (int i = 1; i <= sz; i++) {
            for (int j = 0; j < 5; j++) {
                int x;
                cin >> x;
                v[i].second.push_back(x);
            }
        }

    }

    int ans = 0;

    for (int i = 0; i < items[0].size(); i++) {
        for (int j = 0; j < items[1].size(); j++) {
            for (int k = 0; k < items[2].size(); k++) {
                ans = max(ans, calculate(t, items[0][i], items[1][j], items[2][k]));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}