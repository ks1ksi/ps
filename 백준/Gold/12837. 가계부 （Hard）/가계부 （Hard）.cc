
#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<long long> arr; // 0부터 시작
vector<long long> tree; // 1부터 시작

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
    }
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, idx, diff);
        update(node*2+1, (start+end)/2+1, end, idx, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;

    arr.resize(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1<<h+1);
    tree.resize(tree_size);
    init(1, 0, N-1);

    for (int i = 0; i < Q; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N-1, b-1, c);
            arr[b-1] += c;
        }
        else if (a == 2) {
            cout << sum(1, 0, N-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}