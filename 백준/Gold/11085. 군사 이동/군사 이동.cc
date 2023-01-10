#include <bits/stdc++.h>

using namespace std;

typedef struct _data {
    int s, e, w;

    bool operator<(_data d) {
        return w > d.w;
    }
} Data;

int P, W, C, V;
int p[1000];

int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void Union(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    p[n1] += p[n2];
    p[n2] = n1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> P >> W;
    cin >> C >> V;
    vector<Data> v;

    for (int i = 0; i < W; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        v.push_back({s, e, w});
    }
    memset(p, -1, sizeof(p));
    sort(v.begin(), v.end());
    for (auto d : v) {
        Union(d.s, d.e);
        if (find(C) == find(V)) {
            cout << d.w;
            break;
        }
    }
    return 0;
}