#include <bits/stdc++.h>

using namespace std;

int arr[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 홀수 왼쪽으로 몰기 vs 짝수 왼쪽으로 몰기
    int ans[2] = {0, 0}, cur[2] = {0, 0};

    for (int i = 0; i < n; i++) {
        int idx = arr[i] % 2;
        ans[idx] += i - cur[idx]++;
    }

    cout << min(ans[0], ans[1]);

    return 0;
}