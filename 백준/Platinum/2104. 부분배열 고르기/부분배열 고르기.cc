#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr, tree;
vector<long long> tree2;

int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = start;
    }
    int ret1 = init(start, (start+end)/2, node*2);
    int ret2 = init((start+end)/2+1, end, node*2+1);
    if (arr[ret1] < arr[ret2]) return tree[node] =  ret1;
    else return tree[node] = ret2;
}

long long init2(int start, int end, int node) {
    if (start == end) {
        return tree2[node] = arr[start];
    }
    return tree2[node] = init2(start, (start+end)/2, node*2) + init2((start+end)/2+1, end, node*2+1);
}

int get_min_idx(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return -1;
    else if (left <= start && end <= right) return tree[node];
    int ret1 = get_min_idx(start, (start+end)/2, left, right, node*2);
    int ret2 = get_min_idx((start+end)/2+1, end, left, right, node*2+1);
    if (ret1 == -1) return ret2;
    if (ret2 == -1) return ret1;
    if (arr[ret1] < arr[ret2]) return ret1;
    else return ret2;
}

long long get_sum(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree2[node];
    return get_sum(start, (start+end)/2, left, right, node*2) + get_sum((start+end)/2+1, end, left, right, node*2+1);
}

long long solve(int start, int end) {
    if (start == end) return 1LL*arr[start]*arr[start];
    int minidx = get_min_idx(0, N-1, start, end, 1);
    if (minidx == -1) return 0;
    long long ret = get_sum(0, N-1, start, end, 1)*arr[minidx];
    if (minidx > 0) ret = max(ret, solve(start, minidx-1));
    if (minidx < N-1) ret = max(ret, solve(minidx+1, end));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    arr.resize(N);
    int h = (int)ceil(log2(N));
    int size = (1<<h+1);
    tree.resize(size);
    tree2.resize(size);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(0, N-1, 1);
    init2(0, N-1, 1);
    cout << solve(0, N-1) << '\n';
    return 0;
}