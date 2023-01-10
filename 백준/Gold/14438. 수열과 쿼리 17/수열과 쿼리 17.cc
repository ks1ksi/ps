#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr, tree;

int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = start;
    }
    int ret1 = init(start, (start+end)/2, node*2);
    int ret2 = init((start+end)/2+1, end, node*2+1);
    if (arr[ret1] < arr[ret2]) return tree[node] =  ret1;
    else if (arr[ret1] > arr[ret2]) return tree[node] = ret2;
    else return tree[node] = min(ret1, ret2);
}

int get_min_idx(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return -1;
    else if (left <= start && end <= right) return tree[node];
    int ret1 = get_min_idx(start, (start+end)/2, left, right, node*2);
    int ret2 = get_min_idx((start+end)/2+1, end, left, right, node*2+1);
    if (ret1 == -1) return ret2;
    if (ret2 == -1) return ret1;
    if (arr[ret1] < arr[ret2]) return ret1;
    else if (arr[ret1] > arr[ret2]) return ret2;
    else return min(ret1, ret2);
}

void update(int start, int end, int idx, int value, int node) {
    if (idx < start || end < idx) return;
    if (start == end) {
        tree[node] = start;
        return;
    }
    update(start, (start+end)/2, idx, value, node*2);
    update((start+end)/2+1, end, idx, value, node*2+1);
    if (arr[tree[node*2]] < arr[tree[node*2+1]]) {
        tree[node] = tree[node*2];
    }
    else if (arr[tree[node*2]] > arr[tree[node*2+1]]) {
        tree[node] = tree[node*2+1];
    }
    else {
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    arr.resize(N);
    int h = (int)ceil(log2(N));
    int size = (1<<h+1);
    tree.resize(size);
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
            update(0, N-1, b-1, c, 1);
        }
        else if (a == 2) {
            cout << arr[get_min_idx(0, N-1, b-1, c-1, 1)] << '\n';
        }
    }
    

    return 0;
}