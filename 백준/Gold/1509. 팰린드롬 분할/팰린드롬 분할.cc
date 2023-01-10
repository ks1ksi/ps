#include <bits/stdc++.h>

using namespace std;

string s;
int cache[2500][2500];
int cache2[2500];

int solve(int start, int end) {
    if (start == end) return 1;
    if (end - start == 1 && s[start] == s[end]) return 1;

    int& ret = cache[start][end];
    if (ret != -1) return ret;

    ret = (s[start] == s[end]) && solve(start+1, end-1);
    return ret;
}

int countans(int next) {
    if (next == s.size()) return 0;

    int& ret = cache2[next];
    if (ret != -1) return ret;
    
    ret = 2500;
    for (int i = next; i < s.size(); i++) {
        if (solve(next, i)) {
            ret = min(ret, countans(i+1)+1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));
    cout << countans(0);
    return 0;
}