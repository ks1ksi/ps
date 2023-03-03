#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        bool visited[10000] = {0};
        queue<pair<int, string>> q;
        q.emplace(a, "");
        visited[a] = 1;

        while (!q.empty()) {
            auto [cur, inst] = q.front();
            q.pop();

            if (cur == b) {
                cout << inst << '\n';
                break;
            }

            int d = (cur * 2) % 10000;
            int s = cur == 0 ? 9999 : cur - 1;
            int l = (cur % 1000) * 10 + (cur / 1000);
            int r = (cur / 10) + ((cur % 10) * 1000);

            if (!visited[d]) {
                q.emplace(d, inst + "D");
                visited[d] = 1;
            }
            if (!visited[s]) {
                q.emplace(s, inst + "S");
                visited[s] = 1;
            }
            if (!visited[l]) {
                q.emplace(l, inst + "L");
                visited[l] = 1;
            }
            if (!visited[r]) {
                q.emplace(r, inst + "R");
                visited[r] = 1;
            }
        }
    }

    return 0;
}