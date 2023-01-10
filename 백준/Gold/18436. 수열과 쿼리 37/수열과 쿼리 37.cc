#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 100000;
int N, M;
vector<int> arr(MAX, 0);
vector<pair<int, int>> tree(4*MAX, {0, 0}); // odd, even

void init(int start, int end, int node) {
    if (start == end) {
        if (arr[start]%2) tree[node].first = 1;
        else tree[node].second = 1;
        return;
    }
    init(start, (start+end)/2, node*2);
    init((start+end)/2+1, end, node*2+1);
    tree[node].first = tree[node*2].first + tree[node*2+1].first;
    tree[node].second = tree[node*2].second + tree[node*2+1].second;
}

int query(int start, int end, int left, int right, int qnum, int node) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) {
        if (qnum%2) return tree[node].first;
        else return tree[node].second;
    }
    int q1 = query(start, (start+end)/2, left, right, qnum, node*2);
    int q2 = query((start+end)/2+1, end, left, right, qnum, node*2+1);
    return q1 + q2;
}

void update(int start, int end, int idx, int node) {
    if (idx < start || end < idx) return;
    if (start == end) {
        if (arr[idx]%2) tree[node] = {1, 0};
        else tree[node] = {0, 1};
        return;
    }
    update(start, (start+end)/2, idx, node*2);
    update((start+end)/2+1, end, idx, node*2+1);
    tree[node].first = tree[node*2].first + tree[node*2+1].first;
    tree[node].second = tree[node*2].second + tree[node*2+1].second;
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
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b-1] = c;
            update(0, N-1, b-1, 1);
        }
        else {
            cout << query(0, N-1, b-1, c-1, a, 1) << '\n';
        }
    }
    return 0;
}