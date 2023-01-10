#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
queue<string> q;

vector<string> get_boards(string str) {
    vector<string> ret;
    int zero = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') zero = i;
    }
    if (zero-3 >= 0) {
        string s = str;
        string c;
        c += str[zero-3];
        s.replace(zero-3, 1, "0");
        s.replace(zero, 1, c);
        ret.push_back(s);
    }
    if (zero%3 != 2) {
        string s = str;
        string c;
        c += str[zero+1];
        s.replace(zero+1, 1, "0");
        s.replace(zero, 1, c);
        ret.push_back(s);
    }
    if (zero%3 != 0) {
        string s = str;
        string c;
        c += str[zero-1];
        s.replace(zero-1, 1, "0");
        s.replace(zero, 1, c);
        ret.push_back(s);
    }
    if (zero+3 < 9) {
        string s = str;
        string c;
        c += str[zero+3];
        s.replace(zero+3, 1, "0");
        s.replace(zero, 1, c);
        ret.push_back(s);
    }
    return ret;
}

void bfs() {
    while (!q.empty() && m["123456780"] == 0) {
        string s = q.front();
        q.pop();
        vector<string> boards = get_boards(s);
        for (auto x : boards) {
            if (!m[x] || m[x] > m[s] + 1) {
                m[x] = m[s] + 1;
                q.push(x);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char ch;
    string input;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> ch;
            input += ch;
        }
    }
    m[input] = 1;
    q.push(input);
    bfs();
    if (input == "123456780") cout << 0;
    else cout << m["123456780"] - 1;
    return 0;
}