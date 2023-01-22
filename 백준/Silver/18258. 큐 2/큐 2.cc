#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    deque<int> q;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            q.push_back(x);
        }
        else if (s == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
        else if (s == "size") {
            cout << q.size() << '\n';
        }
        else if (s == "empty") {
            cout << q.empty() << '\n';
        }
        else if (s == "front") {
            q.empty() ? cout << -1 << '\n' : cout << q.front() << '\n';
        }
        else if (s == "back") {
            q.empty() ? cout << -1 << '\n' : cout << q.back() << '\n';
        }
    }

    return 0;
}