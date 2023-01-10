#include <bits/stdc++.h>

using namespace std;

typedef struct _info {
    int x, y, r;
} info;

constexpr int MAX = 1001;
int p[MAX+1]; // 1~1000: 센서, 0, 1001: 벽

int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
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
    cout << fixed << setprecision(6);

    int T;
    cin >> T;
    while (T--) {
        int w, n;
        cin >> w >> n;
        if (!n) {
            cout << w*1.0/2 << '\n';
            continue;
        }
        vector<info> v;
        vector<pair<double, pair<int, int>>> e;
        for (int i = 0; i < n; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            v.push_back({x, y, r});
        }
        for (int i = 0; i < n; i++) {
            double d = v[i].x - v[i].r;
            e.push_back({d, {0, i+1}});
            d = w - v[i].x - v[i].r;
            e.push_back({d, {MAX, i+1}});
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                double d = sqrt(pow(v[i].x-v[j].x, 2)+pow(v[i].y-v[j].y, 2)) - (v[i].r+v[j].r);
                e.push_back({d, {i+1, j+1}});
            }
        }
        memset(p, -1, sizeof(p));
        sort(e.begin(), e.end());
        for (auto p : e) {
            double c = p.first;
            int a = p.second.first;
            int b = p.second.second;
            if (find(a) == find(b)) continue;
            merge(a, b);
            if (find(0) == find(MAX)) {
                if (c < 0) {
                    cout << 0 << '\n';
                }
                else {
                    cout << c/2 << '\n';
                }
                break;
            }
        }
    }
    return 0;
}