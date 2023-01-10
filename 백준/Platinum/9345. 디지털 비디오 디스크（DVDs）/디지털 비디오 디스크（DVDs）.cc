#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int T, N, K;
vector<pair<int, int>> tree;
vector<int> arr;

pair<int, int> init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = {start, start};
    }
    pair<int, int> p1 = init(start, (start+end)/2, node*2);
    pair<int, int> p2 = init((start+end)/2+1, end, node*2+1);
    return tree[node] = {min(p1.first, p2.first), max(p1.second, p2.second)};
}


pair<int, int> query(int start, int end, int left, int right, int node) {
    if (right < start || end < left) return {MAX, 0};
    else if (left <= start && end <= right) return tree[node];

    pair<int, int> p1 = query(start, (start+end)/2, left, right, node*2);
    pair<int, int> p2 = query((start+end)/2+1, end, left, right, node*2+1);

    return {min(p1.first, p2.first), max(p1.second, p2.second)};
}

void update(int start, int end, int idx, int value, int node) {
    if (idx < start || end < idx) return;
    if (start == end) {
        tree[node] = {value, value};
        return;
    }
    update(start, (start+end)/2, idx, value, node*2);
    update((start+end)/2+1, end, idx, value, node*2+1);

    pair<int, int> p1 = tree[node*2];
    pair<int, int> p2 = tree[node*2+1];

    tree[node] = {min(p1.first, p2.first), max(p1.second, p2.second)};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        arr = vector<int>(MAX, 0);
        for (int i = 0; i < N; i++) {
            arr[i] = i;
        }
        tree = vector<pair<int, int>>(4*MAX, {0, 0});
        init(0, N-1, 1);
        for(int i = 0; i < K; i++) {
            int q, a, b;
            cin >> q >> a >> b;
            if (q) {
                pair<int, int> p = query(0, N-1, a, b, 1);
                if (p.first == a && p.second == b) cout << "YES\n";
                else cout << "NO\n";
            }
            else {
                update(0, N-1, a, arr[b], 1);
                update(0, N-1, b, arr[a], 1);
                swap(arr[a], arr[b]);
            }
        }
    }
    return 0;
}