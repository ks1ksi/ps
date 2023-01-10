#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 75000;
int T, N;
vector<int> arr, tree;

void update(int start, int end, int idx, int node) {
    if (idx < start || end < idx) return;
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
    return query(start, (start+end)/2, left, right, node*2) + query((start+end)/2+1, end, left, right, node*2+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        vector<int> sorted;
        vector<pair<int, int>> coords;
        map<int, int> ycoord;
        cin >> N;
        arr = vector<int>(N, 0);
        tree = vector<int>(4*N, 0);
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            coords.push_back({-x, y});
            sorted.push_back(y);
        }
        sort(coords.begin(), coords.end());
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < N; i++) {
            ycoord[sorted[i]] = i;
        }
        long long ans = 0;
        for (auto p : coords) {
            ans += query(0, N-1, 0, ycoord[p.second], 1);
            update(0, N-1, ycoord[p.second], 1);
        }
        cout << ans << '\n';
    }
    return 0;
}