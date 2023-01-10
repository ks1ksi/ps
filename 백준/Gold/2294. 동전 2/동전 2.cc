#include <bits/stdc++.h>

using namespace std;

int arr[101][10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int n, k;
    cin >> n >> k;
    while (n--) {
        int x;
        cin >> x;
        q.push(x);
    }
    
    fill(&(arr[0][0]), &(arr[0][0])+101*10001, 100000);
    
    for (int i = 0; i < 101; i++) {
        arr[i][0] = 0;
    }
    
    
    int t, s = 1;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        for (int i = 1; i <= k; i++) {
            arr[s][i] = arr[s-1][i];
            if (i >= t) {
                arr[s][i] = min(arr[s][i], arr[s][i-t] + 1);
            }
        }
        s++;
    }
    
    if (arr[s-1][k] == 100000) cout << -1;
    else cout << arr[s-1][k];
   
    return 0;
}
