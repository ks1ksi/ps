#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int x;
    v.push_back(-1000000001);
    for (int i = 0; i < N; i++) {
        cin >> x;
        vector<int>::iterator iter = lower_bound(v.begin(), v.end(), x);
        if (iter == v.end()) {
            v.push_back(x);
        }
        else {
            *iter = x;
        }
    }
    cout << v.size()-1;
    return 0;
}