#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    vector<int> v{k};
    for (int i = 1; i < 8; i++) {
        v.push_back(v[i-1]*10+k);
    }

    while (n--) {
        int x;
        cin >> x;
        set<int> cache[9];

        for (int i = 0; i < 8; i++) {
            cache[i+1].insert(v[i]);
        }

        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (i+j > 8) continue;
                for (int a : cache[i]) {
                    for (int b : cache[j]) {
                        cache[i+j].insert(a+b);
                        cache[i+j].insert(a-b);
                        cache[i+j].insert(b-a);
                        cache[i+j].insert(a*b);
                        if (b) cache[i+j].insert(a/b);
                        if (a) cache[i+j].insert(b/a);
                    }
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < 9; i++) {
            if (cache[i].find(x) != cache[i].end()) {
                ans = i;
                break;
            }
        }
        if (ans == -1) cout << "NO\n";
        else cout << ans << '\n';
    }

    return 0;
}
