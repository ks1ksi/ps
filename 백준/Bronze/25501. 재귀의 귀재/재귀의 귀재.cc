#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int recursion(string& s, int l, int r, int& t){
    t++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, t);
}

int isPalindrome(string& s, int& t){
    return recursion(s, 0, s.size()-1, t);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int t = 0;
        cout << isPalindrome(s, t) << ' ' << t << '\n';
    }

    return 0;
}