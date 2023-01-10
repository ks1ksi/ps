#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 100000;
int N, M;
vector<int> arr(MAX), sorted(MAX);
vector<vector<int>> tree(4*MAX);

void init(int start, int end, int node) {
    if (start == end) {
        tree[node].push_back(arr[start]);
        return;
    }
    int mid = (start+end)/2;
    init(start, mid, node*2);
    init(mid+1, end, node*2+1);
    vector<int>& left = tree[node*2];
    vector<int>& right = tree[node*2+1];
    auto l = left.begin();
    auto r = right.begin();
    while(l != left.end() || r != right.end()) {
        if (l == left.end()) {
            tree[node].push_back(*r++);
        } 
        else if (r == right.end()) {
            tree[node].push_back(*l++);
        }
        else {
            if (*l < *r) tree[node].push_back(*l++);
            else tree[node].push_back(*r++);
        }
    }
}

int query(int start, int end, int left, int right, int k, int node) {
    if (end < left || right < start) {
        return 0;
    }
    else if (left <= start && end <= right) {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
    }
    return query(start, (start+end)/2, left, right, k, node*2) + query((start+end)/2+1, end, left, right, k, node*2+1);
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
        cout << query(0, N-1, a-1, b-1, c, 1) << '\n';
    }
    return 0;
}