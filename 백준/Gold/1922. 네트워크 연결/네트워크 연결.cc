#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1001;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    memset(p, -1, sizeof(p));
    int ans = 0;
    for (auto p : v) {
        int c = p.first;
        int a = p.second.first;
        int b = p.second.second;
        if (find(a) == find(b)) continue;
        ans += c;
        merge(a, b);
    }
    cout << ans;
    return 0;
}