#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<array<int, 2>> s;
    int n;
    long long sz, ans = 0;
    cin >> n;
    
    while (n--) {
        int x;
        cin >> x;
        array<int, 2> arr = {x, 1};
        while (!s.empty() && s.top()[0] < x) {
            sz = s.top()[1];
            s.pop();
            if (!s.empty()) {
                ans += sz;
            }
            ans += sz;
            ans += sz*(sz-1)/2;
        }
        if (!s.empty() && s.top()[0] == x) {
            array<int, 2> arr = {x, s.top()[1]+1};
            s.pop();
            s.push(arr);            
        }
        else {
            s.push(arr);
        }
    }
    while (!s.empty()) {
        sz = s.top()[1];
        s.pop();
        if (!s.empty()) {
            ans += sz;
        }
        ans += sz*(sz-1)/2;
    }
    cout << ans;
    return 0;
}