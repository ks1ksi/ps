#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int d = 1e9, sz;

void dfs(int cur, vector<bool>& chk, int dist) {
    int rd = 1e9, rn = -1;
    int ld = 1e9, ln = -1;
    for (int i = 1; i < sz; i++) {
        if (!chk[i]) continue;
        if (rd > abs(i - cur)) {
            rd = abs(i - cur);
            rn = i;
        }
        if (ld > sz - abs(i - cur)) {
            ld = sz - abs(i - cur);
            ln = i;
        }
    }
    
    if (rn == -1 && ln == -1) {
        d = min(dist, d);
        return;
    }
    
    else {
        chk[rn] = 0;
        dfs(rn, chk, dist+rd);
        chk[rn] = 1;
        
        chk[ln] = 0;
        dfs(ln, chk, dist+ld);
        chk[ln] = 1;        
    }
}

int solution(string name) {
    int ans = 0;
    
    sz = name.size();
    vector<bool> chk(sz);
    for (int i = 1; i < sz; i++) {
        if (name[i] != 'A') chk[i] = 1;
    }
    
    dfs(0, chk, 0);
    ans += d;
    
    for (auto c : name) {
        int t = c - 'A';
        ans += (t > 13 ? 26 - t : t);
    }
    
    return ans;
}