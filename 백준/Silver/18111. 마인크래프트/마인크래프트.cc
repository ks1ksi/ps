#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, m, b, c;

// 현재 블록 중 가장 높은 블록과 가장 낮은 블록의 높이를 구함
pair<int, int> get_hi_lo(vector<vector<int>> &v) {
    int hi = 0;
    int lo = 256;

    for (auto &x : v) {
        for (auto &y : x) {
            hi = max(hi, y);
            lo = min(lo, y);
        }
    }

    return {hi, lo};
}

// 전체 블록을 hi로 만드는데 필요한 블록의 개수
int count_hi(vector<vector<int>> &v, int hi) {
    int ret = 0;

    for (auto &x : v) {
        for (auto &y : x) {
            ret += hi - y;
        }
    }

    return ret;
}

// 전체 블록을 lo로 만들기 위해 제거해야 하는 블록의 개수
int count_lo(vector<vector<int>> &v, int lo) {
    int ret = 0;

    for (auto &x : v) {
        for (auto &y : x) {
            ret += y - lo;
        }
    }

    return ret;
}

// 현재 블록의 hi를 한 단계 낮춤
void dec_hi(vector<vector<int>> &v, int &hi) {
    for (auto &x : v) {
        for (auto &y : x) {
            // 높이가 hi인 경우 블록을 제거하고 보유한 블록의 개수를 증가시킴
            if (y == hi) {
                y--;
                b++;
                c += 2;
            }
        }
    }
    hi--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> b;

    vector<vector<int>> v(n, vector<int>(m));

    for (auto &x : v) {
        for (auto &y : x) {
            cin >> y;
        }
    }

    auto [hi, lo] = get_hi_lo(v);
    int ans = INT_MAX;
    int height = hi;

    if (hi == lo) {
        ans = 0;
    }

    while (hi > lo) {
        int c_hi = count_hi(v, hi);
        int c_lo = count_lo(v, lo);

        // 블록을 최고 높이로 맞추는 경우
        if (c_hi <= b && ((ans > c_hi + c) || (ans == c_hi + c && height < hi))) {
            ans = c_hi + c;
            height = hi;
        }

        // 블록을 최저 높이로 맞추는 경우
        if (ans > c_lo * 2 + c) {
            ans = c_lo * 2 + c;
            height = lo;
        }

        dec_hi(v, hi);
    }

    cout << ans << ' ' << height << '\n';

    return 0;
}