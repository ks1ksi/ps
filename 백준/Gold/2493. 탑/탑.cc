#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	stack<pair<int, int>> S1, S2;
	int ans[n] = {};
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pair<int, int> p = {x, i};
		S1.push(p);
	}
	
	while (S1.size()) {
		while (S2.size() && S1.top().first > S2.top().first) {
			ans[S2.top().second] = S1.size();
			S2.pop();
		}
		S2.push(S1.top());
		S1.pop();
	}
	
	for (int i : ans) {
		cout << i << ' ';
	}
	
    return 0;
}

