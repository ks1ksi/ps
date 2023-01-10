#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> arr, tree;

int init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    return tree[node] = init(start, (start+end)/2, node*2) * init((start+end)/2+1, end, node*2+1);
}

int update(int start, int end, int idx, int value, int node) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = value;
    return tree[node] = update(start, (start+end)/2, idx, value, node*2) * update((start+end)/2+1, end, idx, value, node*2+1);
}

int query(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    return query(start, (start+end)/2, left, right, node*2) * query((start+end)/2+1, end, left, right, node*2+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N >> K) {
        arr = vector<int>(N, 0);
        tree = vector<int>(4*N, 0);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (arr[i] > 0) arr[i] = 1;
            else if (arr[i] < 0) arr[i] = -1;
            else arr[i] = 0;
        }
        init(0, N-1, 1);
        for (int i = 0; i < K; i++) {
            char q;
            int a, b;
            cin >> q >> a >> b;
            if (q == 'C') {
                if (b > 0) b = 1;
                else if (b < 0) b = -1;
                else b = 0;
                arr[a-1] = b;
                update(0, N-1, a-1, b, 1);
            }
            else if (q == 'P') {
                int n = query(0, N-1, a-1, b-1, 1);
                if (n > 0) cout << '+';
                else if (n < 0) cout << '-';
                else cout << '0';
            }
        }
        cout << '\n';
    }
    return 0;
}