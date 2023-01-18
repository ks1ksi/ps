#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct Compare {
    bool operator() (const int a, const int b) const {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, Compare> pq;
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        if (!x) {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.emplace(x);
        }
    }

    return 0;
}