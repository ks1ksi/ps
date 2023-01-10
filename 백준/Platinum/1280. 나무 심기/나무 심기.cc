#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000;
const int MOD = 1000000007;
int N;

vector<pair<long, long>> tree(MAX*4, {0, 0}); // sum, count

pair<long, long> query(int start, int end, int left, int right, int node) {
    if (right < start || end < left) return {0, 0};
    else if (left <= start && end <= right) return tree[node];
    pair<long, long> p1 = query(start, (start+end)/2, left, right, node*2);
    pair<long, long> p2 = query((start+end)/2+1, end, left, right, node*2+1);
    return {p1.first+p2.first, p1.second+p2.second};
}

void update(int start, int end, int idx, int node) {
    if (idx < start || end < idx) return;
    if (start == end) {
        tree[node].first += idx;
        tree[node].second++;
        return;
    }
    update(start, (start+end)/2, idx, node*2);
    update((start+end)/2+1, end, idx, node*2+1);
    tree[node].first = tree[node*2].first + tree[node*2+1].first;
    tree[node].second = tree[node*2].second + tree[node*2+1].second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        pair<long, long> ret;
        int x;
        long long tmp = 0;
        cin >> x;

        if (i == 0) {
            update(0, MAX-1, x, 1);
            continue;
        }

        ret = query(0, MAX-1, 0, x-1, 1);
        tmp += ret.second*x - ret.first;
        ret = query(0, MAX-1, x+1, MAX-1, 1);
        tmp += ret.first - ret.second*x;

        ans %= MOD;
        ans *= tmp%MOD;
        update(0, MAX-1, x, 1);
    }
   
    cout << ans%MOD;
    return 0;
}