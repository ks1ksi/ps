#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
int N, M, K;
vector<long long> arr; // 0부터 시작
vector<long long> tree; // 1부터 시작

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = init(node*2, start, (start+end)/2)%MOD * init(node*2+1, (start+end)/2+1, end)%MOD;
    }
}

long long mul(int node, int start, int end, int left, int right) {
    if (left > end || right < start) { // s~e가 구하려는 범위에서 완전 벗어난 경우
        return 1;
    }
    if (left <= start && end <= right) { // s~e가 구하려는 범위에 완전 포함된 경우
        return tree[node]%MOD;
    }
    // 나머지
    return mul(node*2, start, (start+end)/2, left, right)%MOD * mul(node*2+1, (start+end)/2+1, end, left, right)%MOD;
}

void update(int node, int start, int end, int idx, long long value) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node] = value;
        return;
    }
    update(node*2, start, (start+end)/2, idx, value);
    update(node*2+1, (start+end)/2+1, end, idx, value);
    tree[node] = tree[node*2]*tree[node*2+1]%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int x;
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
            update(1, 0, N-1, b-1, c);
            arr[b-1] = c;
        }
        else if (a == 2) {
            cout << mul(1, 0, N-1, b-1, c-1)%MOD << '\n';
        }
    }
    return 0;
}