#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 100000, MOD = 1e9+7;
int N, M;
vector<long long> arr(MAX), tree(4*MAX);
vector<pair<long long, long long>> lazy(4*MAX, {1, 0}); // ax + b

void init(int start, int end, int node) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    init(start, (start+end)/2, node*2);
    init((start+end)/2+1, end, node*2+1);
    tree[node] = (tree[node*2]+tree[node*2+1])%MOD;
}

void propagate(int start, int end, int node) {
    if (lazy[node].first != 1 || lazy[node].second) {
        tree[node] = (tree[node]*lazy[node].first + (end-start+1)*lazy[node].second)%MOD;
        if (start != end) {
            lazy[node*2].second = (lazy[node*2].second*lazy[node].first+lazy[node].second)%MOD;
            lazy[node*2].first = lazy[node*2].first*lazy[node].first%MOD;

            lazy[node*2+1].second = (lazy[node*2+1].second*lazy[node].first+lazy[node].second)%MOD;
            lazy[node*2+1].first = lazy[node*2+1].first*lazy[node].first%MOD;
        }
    }
    lazy[node] = {1, 0};
}

long long query_4(int start, int end, int left, int right, int node) {
    propagate(start, end, node);
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return (query_4(start, (start+end)/2, left, right, node*2) + query_4((start+end)/2+1, end, left, right, node*2+1))%MOD;
}

void query_1(int start, int end, int left, int right, long long value, int node) {
    propagate(start, end, node);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        tree[node] = (tree[node]+(end-start+1)*value)%MOD;
        if (start != end) {
            lazy[node*2].second = (lazy[node*2].second+value)%MOD;
            lazy[node*2+1].second = (lazy[node*2+1].second+value)%MOD;
        }
        return;
    }
    query_1(start, (start+end)/2, left, right, value, node*2);
    query_1((start+end)/2+1, end, left, right, value, node*2+1);
    tree[node] = (tree[node*2]+tree[node*2+1])%MOD;
}

void query_2(int start, int end, int left, int right, long long value, int node) {
    propagate(start, end, node);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        tree[node] = (tree[node]*value)%MOD;
        if (start != end) {
            lazy[node*2].first = (lazy[node*2].first*value)%MOD;
            lazy[node*2+1].first = (lazy[node*2+1].first*value)%MOD;
            lazy[node*2].second = (lazy[node*2].second*value)%MOD;
            lazy[node*2+1].second = (lazy[node*2+1].second*value)%MOD;
        }
        return;
    }
    query_2(start, (start+end)/2, left, right, value, node*2);
    query_2((start+end)/2+1, end, left, right, value, node*2+1);
    tree[node] = (tree[node*2]+tree[node*2+1])%MOD;
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
        int q, x, y;
        long long v;
        cin >> q;
        if (q == 4) {
            cin >> x >> y;
            cout << query_4(0, N-1, x-1, y-1, 1) << '\n';
        }
        else {
            cin >> x >> y >> v;
            if (q == 1) {
                query_1(0, N-1, x-1, y-1, v, 1);
            }
            else if (q == 2) {
                query_2(0, N-1, x-1, y-1, v, 1);
            }
            else if (q == 3) {
                query_2(0, N-1, x-1, y-1, 0, 1);
                query_1(0, N-1, x-1, y-1, v, 1);
            }
        }
    }
    return 0;
}