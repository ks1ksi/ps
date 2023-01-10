#include <bits/stdc++.h>

using namespace std;

const int MAX = 500000;
int N, M;
vector<long long> arr(MAX), tree(1<<20), lazy(1<<20);

long long init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    return tree[node] = init(start, (start+end)/2, node*2) ^ init((start+end)/2+1, end, node*2+1);
}

void propagate(int start, int end, int node) {
    if (lazy[node]) {
        if ((end-start+1)%2) {
            tree[node] ^= lazy[node];
        }
        if (start != end) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

long long query(int start, int end, int left, int right, int node) {
    propagate(start, end, node);
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return query(start, (start+end)/2, left, right, node*2) ^ query((start+end)/2+1, end, left, right, node*2+1);
}

void update(int start, int end, int left, int right, long long diff, int node) {
    propagate(start, end, node);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        if ((end-start+1)%2) {
            tree[node] ^= diff;
        }
        if (start != end) {
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
        return;
    }
    update(start, (start+end)/2, left, right, diff, node*2);
    update((start+end)/2+1, end, left, right, diff, node*2+1);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(0, N-1, 1);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int q, a, b;
        cin >> q;
        if (q == 1) {
            long long c;
            cin >> a >> b >> c;
            if (a > b) swap(a, b);
            update(0, N-1, a, b, c, 1);
        }
        else if (q == 2) {
            cin >> a >> b;
            if (a > b) swap(a, b);
            cout << query(0, N-1, a, b, 1) << '\n';
        }
    }
    return 0;
}