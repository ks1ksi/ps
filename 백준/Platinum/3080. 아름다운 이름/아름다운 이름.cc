#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

struct Trie {
    vector<pair<char, Trie*>> child;
    bool end;

    Trie() {
        end = false;
    }

    ~Trie() {
        for (auto ch : child) {
            delete ch.second;
        }
    }

    void insert(string& s, int idx) {
        if (idx == s.length()) {
            end = true;
            return;
        }
        for (auto ch : child) {
            if (ch.first == s[idx]) {
                ch.second->insert(s, idx+1);
                return;
            }
        }
        pair<char, Trie*> p = {s[idx], new Trie()};
        child.push_back(p);
        p.second->insert(s, idx+1);
    }
};

ll fact(ll n) {
    if (!n) return 1;
    return n*fact(n-1)%MOD;
}

ll solve(Trie* node) {
    ll ret;
    if (node->end) ret = fact(node->child.size()+1);
    else ret = fact(node->child.size());
    for (auto ch : node->child) {
        ret *= solve(ch.second);
        ret %= MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Trie root;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        root.insert(s, 0);
    }
    cout << solve(&root);
    
    return 0;
}