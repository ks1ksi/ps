#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = 100001;
int N;
vector<ll> v(MAX), tree(4*MAX);

int init(int s, int e, int node) {
    if (s == e) return tree[node] = s;
    int idx1 = init(s, (s+e)/2, node*2);
    int idx2 = init((s+e)/2+1, e, node*2+1);
    if (v[idx1] < v[idx2]) return tree[node] = idx1;
    else return tree[node] = idx2;
}

int query(int s, int e, int l, int r, int node) {
    if (s > r || e < l) return -1;
    if (l <= s && e <= r) return tree[node];
    int idx1 = query(s, (s+e)/2, l, r, node*2);
    int idx2 = query((s+e)/2+1, e, l, r, node*2+1);
    if (idx1 == -1) return idx2;
    if (idx2 == -1) return idx1;
    if (v[idx1] < v[idx2]) return idx1;
    else return idx2;
}

ll solve(int l, int r) {
    if (l == r) return v[l];
    ll minidx = query(0, N-1, l, r, 1);
    ll area = v[minidx]*(r-l+1);
    if (minidx-1 > l) area = max(area, solve(l, minidx-1));
    if (minidx+1 < r) area = max(area, solve(minidx+1, r));
    return area;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> v[i];
    init(0, N-1, 1);
    cout << solve(0, N-1) << '\n';

    return 0;
}