#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

int arr[20][20], n;
vector<set<int>> fv;

pair<int, int> countf(int y, int x, int np) { // fav, blk
    int fav = 0, blk = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        if (arr[ny][nx] == 0) blk++;
        else if (fv[np].find(arr[ny][nx]) != fv[np].end()) fav++;
    }
    // cout << fav << ' ' << blk << '\n';
    return make_pair(fav, blk);
}

pair<int, int> f(int np) {
    int y = 0, x = 0;
    int fav = -1, blk = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) continue;
            auto [a, b] = countf(i, j, np);
            if (fav < a) {
                fav = a;
                blk = b;
                y = i;
                x = j;
            }
            else if (fav == a && blk < b) {
                blk = b;
                y = i;
                x = j;
            }
        }
    }

    return make_pair(y, x);
}

int cal() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int fav = 0, tp = arr[i][j];
            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d], nx = j + dx[d];
                if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
                int np = arr[ny][nx];
                if (fv[tp].find(np) != fv[tp].end()) fav++;
            }
            if (fav == 0) continue;
            else ret += pow(10, fav-1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fv.resize(n*n + 1);
    vector<int> sv;
    for (int i = 1; i <= n*n; i++) {
        int x, a, b, c, d;
        cin >> x >> a >> b >> c >> d;
        fv[x].emplace(a);
        fv[x].emplace(b);
        fv[x].emplace(c);
        fv[x].emplace(d);
        sv.emplace_back(x);
    }

    for (auto x : sv) {
        auto [i, j] = f(x);
        arr[i][j] = x;
        // cout << i << ' ' << j << ' ' << x << '\n';
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << cal() << '\n';

    return 0;
}