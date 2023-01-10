#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> dv(int n) {
    vector<int> ret;
    ret.emplace_back(1);

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ret.emplace_back(i);
            if (i != n / i) ret.emplace_back(n / i);
        }
    }

    return ret;
}

bool f(int n, vector<int>& v) {
    int sum = 0;
    for (auto x : v) sum += x;
    return sum > n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v = dv(n);
        if (!f(n, v)) {
            cout << "BOJ 2022\n";
        }
        else {
            bool sw = true;
            for (auto x : v) {
                vector<int> tv = dv(x);
                if (f(x, tv)) {
                    cout << "BOJ 2022\n";
                    sw = false;
                    break;
                }
            }
            if (sw) cout << "Good Bye\n";
        }
    }
    
    return 0;
}