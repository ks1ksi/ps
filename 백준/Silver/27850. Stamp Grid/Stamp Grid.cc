#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, m;

vector<vector<vector<int>>> rotated_vectors(vector<vector<int>>& v) {
    vector<vector<vector<int>>> ret;
    
    vector<vector<int>> rotated = v;
    ret.emplace_back(rotated);

    for (int i = 0; i < 3; i++) {
        vector<vector<int>> tmp(m, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = rotated[j][(m-1)-i];
            }
        }
        rotated = tmp;
        ret.emplace_back(rotated);   
    }

    return ret;
}

bool check(int r, int c, vector<vector<int>>& v1, vector<vector<int>>& v2) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (v2[i][j] == 1 && v1[i+r][j+c] == 0) return 0;
        }
    }
    return 1;
}

void stamp(int r, int c, vector<vector<int>>& v1, vector<vector<int>>& v2) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (v2[i][j]) {
                v1[i+r][j+c] = 2;
            }
        }
    }
}

bool solve(vector<vector<int>>& v1, vector<vector<int>>& v2) {
    auto rv = rotated_vectors(v2);

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            for (auto& vv : rv) {
                if (check(i, j, v1, vv)) {
                    stamp(i, j, v1, vv);
                }
            }
        }
    }

    for (auto& v : v1) {
        for (auto x : v) {
            if (x == 1) return 0;
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> v1(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char x;
                cin >> x;
                if (x == '*') v1[i][j] = 1;
            }
        }

        cin >> m;
        vector<vector<int>> v2(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                char x;
                cin >> x;
                if (x == '*') v2[i][j] = 1;
            }
        }

        auto rv = rotated_vectors(v2);
        if (solve(v1, v2)) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}