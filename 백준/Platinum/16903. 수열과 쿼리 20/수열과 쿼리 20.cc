#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* child[2];
    bool end;
    int cnt;

    Trie() {
        memset(child, 0, sizeof(child));
        end = false;
        cnt = 1;
    }

    ~Trie() {
        for (int i = 0; i < 2; i++) {
            if (child[i]) delete child[i];
        }
    }

    void insert(int x, int idx) {
        if (idx < 0) {
            end = true;
            return;
        }
        bool next = x&(1<<idx);
        if (!child[next]) child[next] = new Trie();
        else child[next]->cnt++;
        child[next]->insert(x, idx-1);
    }

    void remove(int x, int idx) {
        cnt--;
        if (idx < 0) return;
        bool next = x&(1<<idx);
        child[next]->remove(x, idx-1);
    }
};

int solve(Trie* node, int x, int idx) {
    if (idx < 0) return 0;
    bool next = x&(1<<idx);
    if (node->child[0] && node->child[0]->cnt && node->child[1] && node->child[1]->cnt) return solve(node->child[!next], x, idx-1) + (1<<idx);
    else return node->child[0] && node->child[0]->cnt ? solve(node->child[0], x, idx-1) + (x&(1<<idx))^0 : solve(node->child[1], x, idx-1) + (x&(1<<idx))^(1<<idx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Trie root;
    root.insert(0, 29);
    int m;
    cin >> m;
    while (m--) {
        int q, x;
        cin >> q >> x;
        if (q == 1) root.insert(x, 29);
        else if (q == 2) root.remove(x, 29);
        else if (q == 3) cout << solve(&root, x, 29) << '\n';
    }
    
    return 0;
}