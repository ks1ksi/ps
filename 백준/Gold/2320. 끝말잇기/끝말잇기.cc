#include <bits/stdc++.h>

using namespace std;

int N;
string words[16];
int cache[5][1<<16]; // aeiou

int getcharnum(string s, int idx) {
    if (s[idx] == 'A') return 0;
    else if (s[idx] == 'E') return 1;
    else if (s[idx] == 'I') return 2;
    else if (s[idx] == 'O') return 3;
    else if (s[idx] == 'U') return 4;
    else return -1;
}

int solve(int lastword, int cur) {
    if (cur == (1<<N)-1) return 0;
    
    int lastchar = getcharnum(words[lastword], words[lastword].size()-1);
    int& ret = cache[lastchar][cur];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i = 0; i < N; i++) {
        if (cur&(1<<i)) continue;
        if (lastchar != getcharnum(words[i], 0)) continue;
        ret = max(ret, solve(i, cur|(1<<i)) + (int)words[i].size());
    }
    return ret;    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        memset(cache, -1, sizeof(cache));
        ans = max(ans, solve(i, 1<<i) + (int)words[i].size());
    }
    cout << ans;
    return 0;
}