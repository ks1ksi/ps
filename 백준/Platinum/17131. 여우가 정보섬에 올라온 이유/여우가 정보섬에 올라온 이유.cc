#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 200000, MOD = 1e9+7;
int N;
vector<pair<pair<int, int>, int>> arr, rarr;
vector<int> tree(8*MAX, 0);

void update(int start, int end, int idx, int node) {
    if (idx < start || end < idx) return ;
    if (start == end) {
        tree[node]++;
        return;
    }
    update(start, (start+end)/2, idx, node*2);
    update((start+end)/2+1, end, idx, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long query(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return (query(start, (start+end)/2, left, right, node*2) + query((start+end)/2+1, end, left, right, node*2+1))%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({{x, y}, i});
        rarr.push_back({{-x, y}, i});
    }

    sort(arr.begin(), arr.end());
    sort(rarr.begin(), rarr.end());
    vector<long long> cnt(N);

    for (auto i = arr.begin(); i != arr.end(); i++) {
        int y = (*i).first.second + MAX;
        int idx = (*i).second;
        cnt[idx] = query(0, 2*MAX, y+1, 2*MAX, 1);
        update(0, 2*MAX, y, 1);
    }

    tree = vector<int>(8*MAX, 0);
    long long ans = 0;

    for (auto i = rarr.begin(); i != rarr.end(); i++) {
        int y = (*i).first.second + MAX;
        int idx = (*i).second;
        long long v = cnt[idx]*query(0, 2*MAX, y+1, 2*MAX, 1);
        ans = (ans+v)%MOD;
        update(0, 2*MAX, y, 1);
    }

    cout << ans << '\n';
    return 0;
}