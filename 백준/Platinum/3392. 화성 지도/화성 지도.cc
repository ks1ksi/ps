#include <bits/stdc++.h>

using namespace std;

typedef struct _Data {
    int x, y1, y2;
    int t;
    bool operator< (struct _Data d) {
        return x < d.x;
    }
} Data;

int N;
vector<Data> arr;
vector<pair<int, int>> tree(4*30000); // 0보다 큰 리프 노드의 개수, 해당 구간에 선이 생기면 +1, 사라지면 -1

void update(int start, int end, int left, int right, int diff, int node) {
    if (end < left || right < start) return;
    if (left <= start && end <= right) tree[node].second += diff;
    else {
        update(start, (start+end)/2, left, right, diff, node*2);
        update((start+end)/2+1, end, left, right, diff, node*2+1);
    }
    if (tree[node].second > 0) tree[node].first = end-start+1;
    else {
        if (start == end) tree[node].first = 0;
        else tree[node].first = tree[node*2].first + tree[node*2+1].first;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr.push_back({x1, y1, y2, 1});
        arr.push_back({x2, y1, y2, -1});
    }
    sort(arr.begin(), arr.end());
    int tmpx = 0, ans = 0;
    for (int i = 0; i < 2*N; i++) {
        ans += (arr[i].x-tmpx)*tree[1].first;
        update(0, 30000, arr[i].y1, arr[i].y2-1, arr[i].t, 1);
        tmpx = arr[i].x;
    }
    cout << ans;
    return 0;
}