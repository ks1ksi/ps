#include <bits/stdc++.h>

using namespace std;

unordered_set<string> team;

struct Trie {
    map<char, Trie*> child;
    bool end;
    bool removable;
    char al;

    Trie() {
        end = false;
        removable = false;
    }

    ~Trie() {
        for (auto ch : child) {
            if (ch.second) delete ch.second;
        }
    }

    void insert(string& s, int idx, bool rm) {
        removable = rm;
        if (idx == s.length()) {
            if (rm) end = true;
            return;
        }
        if (!child[s[idx]]) {
            child[s[idx]] = new Trie();
        }
        child[s[idx]]->al = s[idx];
        child[s[idx]]->insert(s, idx+1, rm);
    }
};

int solve(Trie* node) {
    if (node->removable) {
        // cout << node->al << ' ';
        return 1;
    }
    int ans = node->end ? 1 : 0;
    for (auto ch : node->child) {
        ans += solve(ch.second);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        Trie root;
        int n1;
        cin >> n1;
        while (n1--) {
            string s;
            cin >> s;
            root.insert(s, 0, true);
        }
        int n2;
        cin >> n2;
        while (n2--) {
            string s;
            cin >> s;
            root.insert(s, 0, false);
        }
        cout << solve(&root) << '\n';
    }
    
    return 0;
}