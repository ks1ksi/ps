#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct tdata {
    ll len, cnt;
    bool l, r;
    ll sz_l, sz_r;
};

constexpr int MAX = 200000;
int N, Q;
vector<tdata> tree(MAX*4);
bool arr[MAX], lazy[4*MAX];

tdata init(int s, int e, int n) {
    if (s == e) {
        return tree[n] = {1, 1, arr[s], arr[e], 1, 1};
    }
    tdata t1 = init(s, (s+e)/2, n*2); // left seg
    tdata t2 = init((s+e)/2+1, e, n*2+1); // right seg
    tdata t3 = {t1.len + t2.len, t1.cnt + t2.cnt, t1.l, t2.r, t1.sz_l, t2.sz_r};
    // calculate subarray cnt, light/left most subarray size
    if (t1.len && t2.len && t1.r != t2.l) {
        ll lr = t1.sz_r + t2.sz_l;
        t3.cnt += (lr*(lr+1)/2 - t1.sz_r*(t1.sz_r+1)/2 - t2.sz_l*(t2.sz_l+1)/2);
        if (t1.sz_l == t1.len) t3.sz_l = t1.len + t2.sz_l;
        if (t2.sz_l == t2.len) t3.sz_r = t2.len + t1.sz_r;
    }
    return tree[n] = t3;
}

void propagate(int s, int e, int n) {
    if (lazy[n]) {
        tree[n].l = !(tree[n].l);
        tree[n].r = !(tree[n].r);
        if (s != e) {
            lazy[n*2] ^= 1;
            lazy[n*2+1] ^= 1;
        }
        lazy[n] = 0;
    }
}

void update(int s, int e, int l, int r, int n) {
    propagate(s, e, n);
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        tree[n].l = !(tree[n].l);
        tree[n].r = !(tree[n].r);
        if (s != e) {
            lazy[n*2] ^= 1;
            lazy[n*2+1] ^= 1;
        }
        return;
    }
    update(s, (s+e)/2, l, r, n*2);
    update((s+e)/2+1, e, l, r, n*2+1);

    tdata t1 = tree[n*2];
    tdata t2 = tree[n*2+1];
    tdata t3 = {t1.len + t2.len, t1.cnt + t2.cnt, t1.l, t2.r, t1.sz_l, t2.sz_r};
    if (!t1.len) {
        t3.l = t2.l;
        t3.sz_l = t2.sz_l;
    }
    if (!t2.len) {
        t3.r = t1.r;
        t3.sz_r = t1.sz_r;
    }
    if (t1.len && t2.len && t1.r != t2.l) {
        ll lr = t1.sz_r + t2.sz_l;
        t3.cnt += (lr*(lr+1)/2 - t1.sz_r*(t1.sz_r+1)/2 - t2.sz_l*(t2.sz_l+1)/2);
        if (t1.sz_l == t1.len) t3.sz_l = t1.len + t2.sz_l;
        if (t2.sz_l == t2.len) t3.sz_r = t2.len + t1.sz_r;
    }
    tree[n] = t3;
    return;
}

tdata query(int s, int e, int l, int r, int n) {
    propagate(s, e, n);
    if (e < l || r < s) return {0, 0, 0, 0, 0, 0};
    if (l <= s && e <= r) return tree[n];

    tdata t1 = query(s, (s+e)/2, l, r, n*2);
    tdata t2 = query((s+e)/2+1, e, l, r, n*2+1);
    tdata t3 = {t1.len + t2.len, t1.cnt + t2.cnt, t1.l, t2.r, t1.sz_l, t2.sz_r};
    if (!t1.len) {
        t3.l = t2.l;
        t3.sz_l = t2.sz_l;
    }
    if (!t2.len) {
        t3.r = t1.r;
        t3.sz_r = t1.sz_r;
    }
    if (t1.len && t2.len && t1.r != t2.l) {
        ll lr = t1.sz_r + t2.sz_l;
        t3.cnt += (lr*(lr+1)/2 - t1.sz_r*(t1.sz_r+1)/2 - t2.sz_l*(t2.sz_l+1)/2);
        if (t1.sz_l == t1.len) t3.sz_l = t1.len + t2.sz_l;
        if (t2.sz_l == t2.len) t3.sz_r = t2.len + t1.sz_r;
    }
    return t3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(0, N-1, 1);

    while (Q--) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            update(0, N-1, l-1, r-1, 1);
        }
        else {
            cout << query(0, N-1, l-1, r-1, 1).cnt << '\n';
        }
    }

    return 0;
}