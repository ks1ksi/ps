#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	long long n, cnt, ans = 0;
	stack<long long> s1;
	stack<pair<long long, long long>> s2;
	cin >> n;
	while (n--) {
		long long x;
		cin >> x;
		s1.push(x);
	}
	
	while (s1.size()) {
		cnt = 0;
		while (s2.size() && s1.top() > s2.top().first) {
			ans += s2.top().second;
			cnt += (s2.top().second+1);
			s2.pop();
		}
		s2.push({s1.top(), cnt});
		s1.pop();
	}
	
	while (s2.size()) {
		ans += s2.top().second;
		s2.pop();
	}
	cout << ans;
	
    return 0;
}


