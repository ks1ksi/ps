#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 10001;
int N;
int w[MAX];
vector<int> adj[MAX], tree[MAX];
bool visited[MAX];
int cache[MAX][2];
vector<int> ans;

int solve(int cur, int p) { // 현재 노드, 부모 노드 선택 여부
    int& ret = cache[cur][p];

    if (!tree[cur].size()) {
        if (p) return ret = 0;
        else return ret = w[cur];
    }

    if (ret != -1) return ret;

    int ret1 = 0, ret2 = 0;
    for (int x : tree[cur]) {
        ret1 += solve(x, 0);
    }
    if (!p) {
        ret2 += w[cur];
        for (int x : tree[cur]) {
            ret2 += solve(x, 1);
        }
    }
    ret = max(ret1, ret2);
    return ret;
}

void track(int cur, int p) {
    if (!p && cache[cur][0] > cache[cur][1]) {
        ans.push_back(cur);
        for (int x : tree[cur]) {
            track(x, 1);
        }
    }
    else {
        for (int x : tree[cur]) {
            track(x, 0);
        }
    }
}

void make_tree(int cur) {
    visited[cur] = true;
    for (int x : adj[cur]) {
        if (!visited[x]) {
            visited[x] = true;
            tree[cur].push_back(x);
            make_tree(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i < N+1; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // for (int i = 1; i < N+1; i++) {
    //     visited[i] = true;
    //     for (int x : adj[i]) {
    //         if (!visited[x]) {
    //             visited[x] = true;
    //             tree[i].push_back(x);
    //         }
    //     }
    // }

    // for (int i = 1; i < N+1; i++) {
    //     cout << i << ": ";
    //     for (int x : tree[i]) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }

    // for (int i = 1; i < N+1; i++) {
    //     cout << w[i] << ' ';
    // }
    // cout << '\n';
    adj[0].push_back(1);
    make_tree(0);
    memset(cache, -1, sizeof(cache));
    cout << solve(0, 0) << '\n';
    // for (int i = 0; i < N+1; i++) {
    //     cout << cache[i][0] << ' ' << cache[i][1] << '\n';
    // }
    track(1, 0);
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << ' ';
    }
    return 0;
}