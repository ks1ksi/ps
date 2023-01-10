#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 5000001;
int arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < MAX; i++) {
        arr[i] = i;
    }

    for (int i = 2; i < MAX; i++) {
        if (arr[i] == i) {
            for (int j = i+i; j < MAX; j+=i) {
                if (arr[j] == j) arr[j] = i;
            }
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        while (k != 1) {
            cout << arr[k] << ' ';
            k /= arr[k];
        }
        cout << '\n';
    }

    return 0;
}