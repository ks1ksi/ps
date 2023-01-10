#include <bits/stdc++.h>

using namespace std;

#define int long long

int N, K;
int cache[1<<15][100], arr[15], pre[51];
vector<string> v;

int solve(int check, int mod) {
    if (check == (1<<N)-1) {
        return mod ? 0 : 1;
    }

    int& ret = cache[check][mod];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < N; i++) {
        if (check & (1<<i)) continue;
        int m = mod*pre[v[i].length()]%K;
        ret += solve(check|(1<<i), (m+arr[i])%K);
    }
    
    return ret;                   
}

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int fact(int n) {
    if (n == 1) return 1;
    return n*fact(n-1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    cin >> K;

    pre[0] = 1;
    for (int i = 1; i < 51; i++) {
        pre[i] = pre[i-1]*10%K;
    }

    for (int i = 0; i < N; i++) {
        int m = 0;
        for (char& c : v[i]) {
            m = m*10 + (c-'0');
            m %= K;
        }
        arr[i] = m;
    }

    memset(cache, -1, sizeof(cache));
    
    int a = solve(0, 0);
    int b = fact(N);
    int g = gcd(a, b);
    cout << a/g << '/' << b/g;

    return 0;
}