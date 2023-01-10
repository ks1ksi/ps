#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h, t;
    cin >> n >> h >> t;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.emplace(x);
    }

    int cnt = 0;
    while (t-- && pq.top() >= h) {
        int g = pq.top();
        if (g == 1) break;
        pq.pop();
        pq.push(g/2);
        cnt++;
    }

    if (h > pq.top()) cout << "YES\n" << cnt;
    else cout << "NO\n" << pq.top();
    
    return 0;
}