#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* child[26];
    bool end;
    int max_depth;

    Trie() {
        memset(child, 0, sizeof(child));
        end = false;
        max_depth = 0;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (child[i]) delete child[i];
        }
    }

    void insert(string& s, int idx) {
        max_depth = max(max_depth, (int)s.length()-idx);
        if (idx == s.length()) {
            end = true;
            return;
        }
        if (!child[s[idx]-'a']) child[s[idx]-'a'] = new Trie();
        child[s[idx]-'a']->insert(s, idx+1);
    }
};

vector<char> ans;

void solve(Trie* node) {
    if (node->end) ans.push_back('P');
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    for (int i = 0; i < 26; i++) {
        if (node->child[i]) {
            pq.push({node->child[i]->max_depth, i});
        }
    }
    while (!pq.empty()) {
        ans.push_back((char)(pq.top().second+'a'));
        solve(node->child[pq.top().second]);
        pq.pop();
    }
    ans.push_back('-');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Trie root;
    vector<string> v;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        root.insert(s, 0);
    }
    solve(&root);
    while (ans.back() == '-') ans.pop_back();
    cout << ans.size() << '\n';
    for (auto& c : ans) {
        cout << c << '\n';
    }
    return 0;
}