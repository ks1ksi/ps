#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 100000;
int N, M;
vector<int> arr(MAX), tree(1<<21), lazy(1<<21);

int init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    return tree[node] = init(start, (start+end)/2, node*2) + init((start+end)/2+1, end, node*2+1);
}

void propagate(int start, int end, int node) {
    if (lazy[node]) {
        if (lazy[node]%2) {
            tree[node] = abs(tree[node]-(end-start+1));
        }
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

int query(int start, int end, int left, int right, int node) {
    propagate(start, end, node);
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return query(start, (start+end)/2, left, right, node*2) + query((start+end)/2+1, end, left, right, node*2+1);
}

void update(int start, int end, int left, int right, int node) {
    propagate(start, end, node);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        tree[node] = abs(tree[node]-(end-start+1));
        if (start != end) {
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return;
    }
    update(start, (start+end)/2, left, right, node*2);
    update((start+end)/2+1, end, left, right, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a) {
            cout << query(0, N-1, b-1, c-1, 1) << '\n';
        }
        else {
            update(0, N-1, b-1, c-1, 1);
        }
    }
    return 0;
}