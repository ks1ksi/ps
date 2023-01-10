#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int rem = 1000-N;
    int ans = 0;

    ans += rem/500;
    rem %= 500;
    ans += rem/100;
    rem %= 100;
    ans += rem/50;
    rem %= 50;
    ans += rem/10;
    rem %= 10;
    ans += rem/5;
    rem %= 5;
    ans += rem;

    cout << ans;
    
    return 0;
}