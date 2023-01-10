#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* t[26];
    int cnt;
    bool end;

    Trie() {
        memset(t, 0, sizeof(t));
        cnt = 0;
        end = false;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (t[i]) delete t[i];
        }
    }

    void insert(string& s, int idx) {
        if (idx == s.length()) {
            end = true;
            return;
        }
        if (!t[s[idx]-'a']) {
            t[s[idx]-'a'] = new Trie();
            cnt++;
        }
        t[s[idx]-'a']->insert(s, idx+1);
    }

    int solve(string& s, int idx) {
        if (idx == s.length()) return 0;
        if (end || cnt > 1)  return t[s[idx]-'a']->solve(s, idx+1) + 1;
        else return t[s[idx]-'a']->solve(s, idx+1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);

    int n;
    while (cin >> n) {
        Trie root;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            root.insert(v[i], 0);
        }
        double ans = 0;
        if (root.cnt == 1) ans += n;
        for (string& s : v) {
            ans += root.solve(s, 0);
        }
        cout << ans/n << '\n';
    }

    return 0;
}