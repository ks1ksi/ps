#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    int n, x, ans = 0;
    cin >> n;
    s.push(0);
    for (int i = 1; i <= n+1; i++) {
        if (i != n+1) cin >> arr[i];
        while (!s.empty() && arr[s.top()] > arr[i]) {
            x = s.top();
            s.pop();
            ans = max(ans, arr[x]*((x-s.top()-1)+(i-x)));
        }
        s.push(i);
    }
    cout << ans;
    return 0;
}