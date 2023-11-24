#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int p[100001];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    p[a] += p[b];
    p[b] = a;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(p, p + sizeof(p) / sizeof(int), -1);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c, a, b);
    }

    sort(edges.begin(), edges.end());

    int ans = 0;
    for (auto [c, a, b] : edges) {
        if (find(a) == find(b)) continue;
        merge(a, b);
        if (p[find(a)] == -n || p[find(b)] == -n) break;
        ans += c;
    }

    cout << ans << '\n';

    return 0;
}
