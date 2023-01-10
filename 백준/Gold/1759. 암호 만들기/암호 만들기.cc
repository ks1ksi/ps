#include <bits/stdc++.h>

using namespace std;

int L, C;
char arr[15];

void solve(int idx, bool check, int cnt, char* arr, string s) {
    if (idx == C) {
        if (s.size() == L && check && cnt >= 2) {
            cout << s << '\n';
        }
        return;
    }
    
    if (arr[idx] == 'a'
    || arr[idx] == 'e'
    || arr[idx] == 'i'
    || arr[idx] == 'o'
    || arr[idx] == 'u') {
        solve(idx+1, true, cnt, arr, s+arr[idx]);
    }
    
    else {
        solve(idx+1, check, cnt+1, arr, s+arr[idx]);
    }
    
    solve(idx+1, check, cnt, arr, s);
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+C);
    solve(0, false, 0, arr, "");
        
    return 0;
}
