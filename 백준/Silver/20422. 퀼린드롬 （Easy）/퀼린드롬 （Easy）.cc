#include <bits/stdc++.h>

using namespace std;

map<char, char> table = {
    {'A', 'A'}, {'E', '3'}, {'H', 'H'},
    {'I', 'I'}, {'M', 'M'}, {'O', 'O'},
    {'S', '2'}, {'T', 'T'}, {'U', 'U'},
    {'V', 'V'}, {'W', 'W'}, {'X', 'X'},
    {'Y', 'Y'}, {'Z', '5'},
    {'b', 'd'}, {'d', 'b'}, {'i', 'i'},
    {'l', 'l'}, {'m', 'm'}, {'n', 'n'},
    {'o', 'o'}, {'p', 'q'}, {'q', 'p'},
    {'r', '7'}, {'u', 'u'}, {'v', 'v'},
    {'w', 'w'}, {'x', 'x'},
    {'0', '0'}, {'1', '1'}, {'2', 'S'},
    {'3', 'E'}, {'5', 'Z'}, {'7', 'r'},
    {'8', '8'}
};

char convert(char x) {
    if ('a' <= x && x <= 'z') return x-32;
    else if ('A' <= x && x <= 'Z') return x+32;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int len = s.length();

    if (len % 2 && !table[s[len/2]]) {
        if (table[convert(s[len/2])]) s[len/2] = convert(s[len/2]);
        else {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < len/2; i++) {
        if (s[i] == table[s[len-1-i]]) continue;
        else if (convert(s[i]) == table[s[len-1-i]]) {
            s[i] = convert(s[i]);
            continue;
        }
        else if (s[i] == table[convert(s[len-1-i])]) {
            s[len-1-i] = convert(s[len-1-i]);
            continue;
        }
        else if (convert(s[i]) == table[convert(s[len-1-i])]) {
            s[i] = convert(s[i]);
            s[len-1-i] = convert(s[len-1-i]);
            continue;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    cout << s;

    return 0;
}