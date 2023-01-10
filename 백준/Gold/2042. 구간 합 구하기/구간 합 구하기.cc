#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<long long> arr;
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
    if (left > end || right < start) { // s~e가 구하려는 범위에서 완전 벗어난 경우
        return 0;
    }
    if (left <= start && end <= right) { // s~e가 구하려는 범위에 완전 포함된 경우
        return tree[node];
    }
    // 나머지
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
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    int h = (int)ceil(log2(N));
    int tree_size = (1<<h+1);
    tree.resize(tree_size);
    init(1, 0, N-1);

    for (int i = 0; i < M+K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N-1, b-1, c-arr[b-1]);
            arr[b-1] = c;
        }
        else if (a == 2) {
            cout << sum(1, 0, N-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}