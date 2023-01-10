#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
int N;
vector<int> arr(MAX);
vector<int> tree(MAX*4);

void update(int start, int end, int idx, int node) {
    if (idx < start || end < idx) return;
    if (start == end) {
        tree[node]++;
        return;
    }
    update(start, (start+end)/2, idx, node*2);
    update((start+end)/2+1, end, idx, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return query(start, (start+end)/2, left, right, node*2) + query((start+end)/2+1, end, left, right, node*2+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        arr[x] = i;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        int pos = arr[x];
        ans += query(0, MAX-1, pos, MAX-1, 1);
        update(0, MAX-1, pos, 1);
    }
    cout << ans;
    return 0;
}