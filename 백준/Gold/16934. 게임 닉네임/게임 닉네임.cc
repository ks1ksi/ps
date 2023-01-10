#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* t[26];
    int cnt;
    bool end;

    Trie() {
        memset(t, 0, sizeof(t));
        // end = false;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (t[i]) delete t[i];
        }
    }

    void insert(string& s, int idx, bool print) {
        if (idx == s.length()) {
            // end = true;
            return;
        }
        if (print) cout << s[idx];
        if (!t[s[idx]-'a']) {
            t[s[idx]-'a'] = new Trie();
            print = false;
        }
        t[s[idx]-'a']->insert(s, idx+1, print);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    Trie root;
    map<string, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        root.insert(s, 0, true);
        if (m[s]) cout << ++m[s];
        else m[s] = 1;
        cout << '\n';
    }

    return 0;
}