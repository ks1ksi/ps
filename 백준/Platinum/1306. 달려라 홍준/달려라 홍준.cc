#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v, tree;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = v[start];
        return;
    }
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return max(query(node*2, start, (start+end)/2, left, right), query(node*2+1, (start+end)/2+1, end, left, right));
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    v = vector<int>(N);
    tree = vector<int>(4*N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    init(1, 0, N-1);
    for (int i = M-1; i <= N-M; i++) {
        cout << query(1, 0, N-1, i-(M-1), i+(M-1)) << ' ';
    }

    return 0;
}