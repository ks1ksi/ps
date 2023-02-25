#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int N, M, p[500001];

int find(int a) {
    if (p[a] < 0) return a;
    return find(p[a]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    p[a] += p[b];
    p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(p, -1, sizeof(p));

    int cnt = 0;
    bool flag = false;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);

        if (find(a) == find(b)) {
            flag = true;
            cnt++;
            break;
        }
        merge(a, b);
        cnt++;
    }

    if (!flag) cout << 0 << '\n';
    else  cout << cnt << '\n';

    return 0;
}