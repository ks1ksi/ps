#include <bits/stdc++.h>

using namespace std;

int arr[500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = 1e9;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j != i && (arr[j]-arr[i])%(j-i)) continue;
            
            int diff;
            if (j != i) diff = (arr[j]-arr[i])/(j-i);
            else diff = 0;
            
            int cnt = 0;
            for (int k = 0; k < i; k++) {
                if (arr[i] - arr[k] != diff*(i-k)) cnt++;
            }
            
            for (int k = i+1; k < n; k++) {
                if (arr[k] - arr[i] != diff*(k-i)) cnt++;
            }
            ans = min(ans, cnt);
        }
    }
    
    cout << ans;
    
    return 0;
}
