#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
string s = "AEIOU";

int dfs(string cur, string target) {
    if (cur.size() > 5) return 0;
    
    // cout << "cur " << cur << " target " << target << '\n';
    
    if (cur.size() > 0) {
        cnt++;
        if (cur == target) {
            return cnt;
        }
    }
    
    int ret = 0;
    
    for (auto c : s) {
        ret = max(ret, dfs(cur + c, target));
    }
    
    return ret;
}

int solution(string word) {
    int answer = dfs("", word);
    
    return answer;
}