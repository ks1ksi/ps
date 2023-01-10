#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 20001;
int N;
int arr[MAX];
bool visited[MAX];

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<int> v;

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        int cur = i;
        int next = arr[i];
        int cnt = 1;
        while (next != cur) {
            visited[next] = true;
            cnt++;
            next = arr[next];
        }
        v.push_back(cnt);
    }

    long long lcm = 1;
    for (int& x : v) {
        // cout << x << ' ';
        lcm = lcm*x/gcd(lcm, x);
    }

    cout << lcm;

    return 0;
}