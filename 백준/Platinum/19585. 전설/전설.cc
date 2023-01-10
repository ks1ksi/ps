#include <bits/stdc++.h>

using namespace std;

unordered_set<string> team;

struct Trie {
    Trie* t[26];
    bool end;

    Trie() {
        memset(t, 0, sizeof(t));
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
        }
        t[s[idx]-'a']->insert(s, idx+1);
    }

    bool solve(string& s, int idx) {
        if (idx == s.length()) return false;
        if (!t[s[idx]-'a']) return false;
        if (t[s[idx]-'a']->end && team.find(s.substr(idx+1)) != team.end()) return true;
        return t[s[idx]-'a']->solve(s, idx+1);
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Trie root;
    int c, n, q;
    cin >> c >> n;
    while (c--) {
        string s;
        cin >> s;
        root.insert(s, 0);
    }
    while (n--) {
        string s;
        cin >> s;
        team.insert(s);
    }
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (root.solve(s, 0)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}