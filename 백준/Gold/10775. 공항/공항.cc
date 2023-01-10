#include <bits/stdc++.h>

using namespace std;

int G, P;
int p[100001];

int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void Union(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    else {
        p[n2] = n1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> G >> P;
    memset(p, -1, sizeof(p));
    int ans = 0;
    for (int i = 0; i < P; i++) {
        int g;
        cin >> g;
        if (find(g) == 0) break;
        Union(find(g)-1, find(g));
        // cout << find(g) << ' ' << p[find(g)] << '\n';
        ans++;
    }
    cout << ans << '\n';
    return 0;
}