#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, cache[1<<16], sz[16], words[16][26];
string s[16];

int get_cnt(int mask) {
    vector<int> acnt(26, 2e9);
    for (int i = 0; i < 16; i++) {
        if ((mask&(1<<i)) == 0) continue;
        for (int j = 0; j < 26; j++) {
            acnt[j] = min(acnt[j], words[i][j]);
        }
    }
    int ret = 0;
    for (int i = 0; i < 26; i++) {
        ret += acnt[i];
    }
    return ret;
}

int solve(int mask) {
    int& ret = cache[mask];
    if (ret != -1) return ret;
    int cnt = get_cnt(mask);
    if (((mask-1)&mask) == 0) return ret = cnt;

    ret = 2e9;
    // iterate through all of its submasks
    for (int sub = (mask-1)&mask; sub > 0; sub = (sub-1)&mask) {
        ret = min(ret, solve(sub) + solve(mask^sub) - cnt);
        
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (auto c : s[i]) {
            words[i][c-'a']++;
        }
    }

    memset(cache, -1, sizeof(cache));
    cout << solve((1<<N)-1) + 1 << '\n';

    return 0;
}