#include <bits/stdc++.h>

using namespace std;

int N;
const int MAX = 1000000;
vector<int> tree(4*MAX, 0);

void update(int start, int end, int idx, int diff, int node) {
    if (idx < start || end < idx) return;
    tree[node] += diff;
    if (start == end) return;
    update(start, (start+end)/2, idx, diff, node*2);
    update((start+end)/2+1 ,end, idx, diff, node*2+1);
}

int query(int start, int end, int rank, int node) {
    if (start == end) return start;
    if (tree[node*2] < rank) {
        return query((start+end)/2+1, end, rank-tree[node*2], node*2+1);
    }
    else {
        return query(start, (start+end)/2, rank, node*2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            int candy = query(0, MAX-1, b, 1);
            cout << candy+1 << '\n';
            update(0, MAX-1, candy, -1, 1);
        }
        else if (a == 2) {
            cin >> b >> c;
            update(0, MAX-1, b-1, c, 1);
        }
    }
    return 0;
}