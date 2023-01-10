#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = 1e5+1;
int trie[31*MAX][2];
int node = 0;

void insert(int x) {
    int idx = 0;
    for (int i = 30; i >= 0; i--) {
        bool bit = x&(1<<i);
        if (trie[idx][bit] == -1) {
            trie[idx][bit] = ++node;
        }
        idx = trie[idx][bit];
    }
}

int solve(int x) {
    int ret = 0;
    int idx = 0;
    for (int i = 30; i >= 0 ; i--) {
        bool bit = x&(1<<i);
        if (trie[idx][!bit] != -1) {
            idx = trie[idx][!bit];
            ret += (1<<i);
        }
        else {
            idx = trie[idx][bit];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            v[i] = v[i-1]^x;
        }
        memset(trie, -1, sizeof(trie));
        node = 0;
        for (int i = 0; i <= n; i++) {
            insert(v[i]);
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = max(ans, solve(v[i]));
        }
        cout << ans << '\n';
    }
    return 0;
}