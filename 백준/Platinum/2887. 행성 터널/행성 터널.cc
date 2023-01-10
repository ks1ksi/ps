#include <bits/stdc++.h>

using namespace std;

typedef struct _point {
    int x, y, z, n;
} point;

constexpr int MAX = 100001;
int N;
int p[MAX];

int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

bool cmp_x(point p1, point p2) {
    return p1.x < p2.x;
}

bool cmp_y(point p1, point p2) {
    return p1.y < p2.y;
}

bool cmp_z(point p1, point p2) {
    return p1.z < p2.z;
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    p[n1] += p[n2];
    p[n2] = n1;   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<point> v(N);
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = {x, y, z, i};
    }

    vector<pair<int, pair<int, int>>> e;

    sort(v.begin(), v.end(), cmp_x);
    for (int i = 0; i < N-1; i++) {
        e.push_back({abs(v[i].x-v[i+1].x), {v[i].n, v[i+1].n}});
    }
    sort(v.begin(), v.end(), cmp_y);
    for (int i = 0; i < N-1; i++) {
        e.push_back({abs(v[i].y-v[i+1].y), {v[i].n, v[i+1].n}});
    }
    sort(v.begin(), v.end(), cmp_z);
    for (int i = 0; i < N-1; i++) {
        e.push_back({abs(v[i].z-v[i+1].z), {v[i].n, v[i+1].n}});
    }

    sort(e.begin(), e.end());
    memset(p, -1, sizeof(p));
    long long ans = 0;
    for (auto p : e) {
        int c = p.first;
        int a = p.second.first;
        int b = p.second.second;
        if (find(a) == find(b)) continue;
        merge(a, b);
        ans += c;
    }
    cout << ans << '\n';
    
    return 0;
}