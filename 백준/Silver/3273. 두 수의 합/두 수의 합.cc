#include <bits/stdc++.h>
using namespace std;

bool arr[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, x, ans = 0;
	cin >> n;
	while (n--) {
		int idx;
		cin >> idx;
		arr[idx] = true;
	}
	cin >> x;
	
	for (int i = 1; i < x/2+1; i++) {
		if (arr[i] && arr[x-i] && i!=x-i) {
			ans++;
		}
	}
	cout << ans;
    return 0;
}

