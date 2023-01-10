#include <bits/stdc++.h>

using namespace std;

int N, L;
int p[300001];

int find(int n) {
    if (p[n] <= 0) return n;
    return p[n] = find(p[n]);
}

void Union(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    else {
        p[n1] += p[n2];
        p[n2] = n1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;

    memset(p, -1, sizeof(p));

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (-p[find(a)] - p[find(b)] > 0) {
            cout << "LADICA\n";
            Union(a, b);
            p[find(a)]++;
        }
        else {
            cout << "SMECE\n";
        }
    }

    return 0;
}