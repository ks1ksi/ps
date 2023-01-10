#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = 4587520;
int C, N, O;
vector<pair<int, int>> tree(4*MAX); // min, max;
vector<int> lazy(4*MAX);

void propagate(int s, int e, int n) {
    if (lazy[n] != 0) {
        tree[n].first += lazy[n];
        tree[n].second += lazy[n];
        if (s != e) {
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

int query(int s, int e, int l, int r, int n, function<int(int, int)> f) {
    propagate(s, e, n);
    if (e < l || r < s) return -f(N, -N);
    if (l <= s && e <= r) return f(tree[n].first, tree[n].second);
    return f(query(s, (s+e)/2, l, r, n*2, f), query((s+e)/2+1, e, l, r, n*2+1, f));
}

void update(int s, int e, int l, int r, int n, int v) {
    propagate(s, e, n);
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        tree[n].first += v;
        tree[n].second += v;
        if (s != e) {
            lazy[n*2] += v;
            lazy[n*2+1] += v;
        }
        return;
    }
    update(s, (s+e)/2, l, r, n*2, v);
    update((s+e)/2+1, e, l, r, n*2+1, v);
    tree[n].first = min(tree[n*2].first, tree[n*2+1].first);
    tree[n].second = max(tree[n*2].second, tree[n*2+1].second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> N >> O;
    while (O--) {
        string s;
        int l, r, v;
        cin >> s;
        if (s == "state") {
            cin >> l;
            cout << query(0, C-1, l, l, 1, [](int a, int b){ return min(a, b); }) << '\n';
        }
        else {
            if (s == "groupchange") cin >> l >> r >> v;
            else if (s == "change") {
                cin >> l >> v;
                r = l;
            }
            if (v > 0) {
                int maxv = query(0, C-1, l, r, 1, [](int a, int b){ return max(a, b); });
                int updv = min(maxv + v, N);
                cout << updv - maxv << '\n';
                update(0, C-1, l, r, 1, updv - maxv);
            }
            else {
                int minv = query(0, C-1, l, r, 1, [](int a, int b){ return min(a, b); });
                int updv = max(0, minv + v);
                cout << updv - minv << '\n';
                update(0, C-1, l, r, 1, updv - minv);
            }
        }
    }

    return 0;
}