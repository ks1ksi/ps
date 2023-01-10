#include <bits/stdc++.h>

using namespace std;

int N, W, cache[1001][1001];
vector<pair<int ,int>> v;

int get_dist(int cur, int next, int p) {
    int cx = v[cur].first;
    int cy = v[cur].second;
    if (!cur) {
        if (p == 1) {
            cx = 1;
            cy = 1;
        }
        else if (p == 2) {
            cx = N;
            cy = N;
        }
    }
    return abs(v[next].first-cx) + abs(v[next].second-cy);
}

int solve(int p1, int p2, int next) {
    int& ret = cache[p1][p2];
    if (ret != -1) return ret;

    if (next == W+1) return ret = 0;

    int r1 = solve(next, p2, next+1) + get_dist(p1, next, 1);
    int r2 = solve(p1, next, next+1) + get_dist(p2, next, 2);
    ret = min(r1, r2);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W;

    v = vector<pair<int, int>>(W+1);

    for (int i = 1; i < W+1; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    memset(cache, -1, sizeof(cache));

    cout << solve(0, 0, 1) << '\n';

    // for (int i = 0; i < W+1; i++) {
    //     for (int j = 0; j < W+1; j++) {
    //         cout << cache[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<int> track;
    int p1 = 0, p2 = 0, next = 1;
    while (next != W+1) {
        if (cache[p1][p2] - cache[next][p2] == get_dist(p1, next, 1)) {
            track.push_back(1);
            p1 = next;
            next++;
        }
        else {
            track.push_back(2);
            p2 = next;
            next++;
        }
    }
    
    for (int x : track) {
        cout << x << '\n';
    }

    return 0;
}