#include <bits/stdc++.h>

using namespace std;

int arr[10001];
vector<int> v;

void func() {
    for (int i = 2; i < 10001; i++) {
        if (arr[i]) {
            int x = i+i;
            while (x < 10001) {
                arr[x] = 0;
                x+=i;
            }
        }
    }

    int tmp = 2;
    for (int i = 3; i < 10001; i++) {
        if (arr[i]) {
            v.push_back(tmp*i);
            tmp = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < 10001; i++) {
        arr[i] = i;
    }

    func();

    cout << *upper_bound(v.begin(), v.end(), n);

    return 0;
}