#include <bits/stdc++.h>

using namespace std;

const int MAX = 500001;
int N;
vector<int> arr, v;
vector<int> tree(MAX*4);
map<int, int> m;

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
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        v.push_back(x);
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++) {
        m[arr[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << query(0, N-1, m[v[i]], N-1, 1)+1 << '\n';
        update(0, N-1, m[v[i]], 1);
    }
    return 0;
}