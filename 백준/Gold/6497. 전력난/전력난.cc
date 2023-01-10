#include <bits/stdc++.h>

using namespace std;

#define int long long

constexpr int MAX = 200001;
int N, M;
int p[MAX];

int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    p[n1] += p[n2];
    p[n2] = n1;   
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> N >> M;
        if (!N && !M) break;
        int ans = 0, tc = 0;
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({c, {a, b}});
            tc += c;
        }
        sort(v.begin(), v.end());
        memset(p, -1, sizeof(p));
        for (auto p : v) {
            int c = p.first;
            int a = p.second.first;
            int b = p.second.second;
            if (find(a) == find(b)) continue;
            ans += c;
            merge(a, b);
        }
        cout << tc - ans << '\n';
    }

    return 0;
}