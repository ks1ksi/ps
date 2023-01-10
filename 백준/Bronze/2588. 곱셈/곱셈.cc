#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, tmp;
    cin >> a >> b;

    int sum = 0;

    tmp = a*(b%10);
    cout << tmp << '\n';
    b/=10;
    sum += tmp;

    tmp = a*(b%10);
    cout << tmp << '\n';
    b/=10;
    sum += tmp*10;

    tmp = a*(b%10);
    cout << tmp << '\n';
    b/=10;
    sum += tmp*100;

    cout << sum;

    return 0;
}



