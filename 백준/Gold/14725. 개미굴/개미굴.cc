#include <bits/stdc++.h>

using namespace std;

struct Trie {
    map<string, Trie*> m;

    Trie() {
    }

    ~Trie() {
        for (auto iter : m) {
            delete iter.second;
        }
    }

    void insert(vector<string>& v, vector<string>::iterator iter) {
        if (iter == v.end()) return;
        if (m.find(*iter) == m.end()) {
            m[*iter] = new Trie();
        }
        m[*iter]->insert(v, iter+1);
    }

    void print(int h) {
        for (auto iter : m) {
            for (int i = 0; i < h*2; i++) cout << '-';
            cout << iter.first << '\n';
            iter.second->print(h+1);
        }
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    Trie root;
    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<string> v;
        int K;
        cin >> K;
        while (K--) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        root.insert(v, v.begin());
    }

    root.print(0);

    return 0;
}