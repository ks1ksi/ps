#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* child[2];
    bool end;
    int cnt;

    Trie() {
        memset(child, 0, sizeof(child));
        end = false;
        cnt = 0;
    }

    ~Trie() {
        for (int i = 0; i < 2; i++) {
            if (child[i]) delete child[i];
        }
    }

    void insert(int x, int idx) {
        cnt++;
        if (idx < 0) {
            end = true;
            return;
        }
        bool next = x&(1<<idx);
        if (!child[next]) child[next] = new Trie();
        child[next]->insert(x, idx-1);
    }

    void remove(int x, int idx) {
        cnt--;
        if (idx < 0) return;
        bool next = x&(1<<idx);
        child[next]->remove(x, idx-1);
    }

    // void remove_min(int idx) {
    //     cnt--;
    //     if (idx < 0) return;
    //     bool next = child[0] && child[0]->cnt ? 0 : 1;
    //     child[next]->remove_min(idx-1);
    // }

    // void remove_max(int idx) {
    //     cnt--;
    //     if (idx < 0) return;
    //     bool next = child[1] && child[1]->cnt ? 1 : 0;
    //     child[next]->remove_min(idx-1);
    // }
};

int solve(Trie* node, int x, int idx) {
    if (idx < 0) return 0;
    bool next = x&(1<<idx);
    if (node->child[0] && node->child[0]->cnt && node->child[1] && node->child[1]->cnt) return solve(node->child[!next], x, idx-1) + (1<<idx);
    else return node->child[0] && node->child[0]->cnt ? solve(node->child[0], x, idx-1) + (x&(1<<idx))^0 : solve(node->child[1], x, idx-1) + (x&(1<<idx))^(1<<idx);
}

int solve_min(Trie* node, int x, int idx) {
    if (idx < 0) return 0;
    bool next = x&(1<<idx);
    if (node->child[0] && node->child[0]->cnt && node->child[1] && node->child[1]->cnt) return solve_min(node->child[next], x, idx-1);
    else return node->child[0] && node->child[0]->cnt ? solve_min(node->child[0], x, idx-1) + (x&(1<<idx))^0 : solve_min(node->child[1], x, idx-1) + (x&(1<<idx))^(1<<idx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        Trie root;
        set<int> st;
        int n, q;
        cin >> n >> q;
        while (n--) {
            int x;
            cin >> x;
            if (!st.count(x)) {
                root.insert(x, 29);
                st.insert(x);
            }
        }
        while (q--) {
            int qn, x;
            cin >> qn;
            if (qn < 4) cin >> x;
            if (qn == 1) cout << solve_min(&root, x, 29) << '\n';
            else if (qn == 2) cout << solve(&root, x, 29) << '\n';
            else if (qn == 3) {
                if (!st.count(x)) {
                    root.insert(x, 29);
                    st.insert(x);
                }
                cout << root.cnt << '\n';
            }
            else if (qn == 4) {
                cout << *st.begin() << '\n';
                root.remove(*st.begin(), 29);
                st.erase(*st.begin());
            }
            else if (qn == 5) {
                cout << *st.rbegin() << '\n';
                root.remove(*st.rbegin(), 29);
                st.erase(*st.rbegin());
            }
        }
    }

    return 0;
}