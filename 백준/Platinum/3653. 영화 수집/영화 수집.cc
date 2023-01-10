#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int T, N, M, TOP;
vector<int> v;
vector<int> dvdpos; // dvd가 위치한곳 저장.

void update(int start, int end, int idx, int value, int node) {
    if (idx < start || end < idx) return;
    if (start == end) {
        v[node] = value;
        return;
    }
    update(start, (start+end)/2, idx, value, node*2);
    update((start+end)/2+1, end, idx, value, node*2+1);
    v[node] = v[node*2] + v[node*2+1];
}

int query(int start, int end, int left, int right, int node) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return v[node];
    return query(start, (start+end)/2, left, right, node*2) + query((start+end)/2+1, end, left, right, node*2+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        TOP = MAX;
        dvdpos = vector<int>(MAX+1, 0);
        v = vector<int>(4*2*MAX, 0);
        for (int i = 0; i < N; i++) {
            update(0, 2*MAX-1, i, 1, 1);
            dvdpos[i+1] = N-i-1;
        }
        for (int i = 0; i < M; i++) {
            int x;
            cin >> x;
            cout << query(0, 2*MAX-1, dvdpos[x]+1, 2*MAX-1, 1) << ' ';
            update(0, 2*MAX-1, dvdpos[x], 0, 1);
            update(0, 2*MAX-1, TOP, 1, 1);
            dvdpos[x] = TOP++;
        }
        cout << '\n';
    } 
    return 0;
}