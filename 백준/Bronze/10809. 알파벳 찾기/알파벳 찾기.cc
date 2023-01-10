#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[26];
    memset(arr, -1, sizeof(arr));
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (arr[s[i]-'a'] == -1) arr[s[i]-'a'] = i;
    }

    for (int x : arr) {
        cout << x << ' ';
    }
    return 0;
}