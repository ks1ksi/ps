#include <bits/stdc++.h>

using namespace std;

int cache[101][101][101];

int solve(int a, int b, int c) {
    int& ret = cache[a][b][c];
    if (ret != -1) return ret;

    if (a <= 50 || b <= 50 || c <= 50) {
        return ret = 1;
    }

    if (a > 70 || b > 70 || c > 70) {
        return ret = solve(70, 70, 70);
    }

    if (a < b && b < c) {
        return ret = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
    }

    else return ret = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    memset(cache, -1, sizeof(cache));
    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a+50, b+50, c+50) << '\n';
    }
    return 0;
}