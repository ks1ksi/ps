#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int N, K;
	cin >> N >> K;
	list<int> L1, L2;
	for (int i = 0; i < N; i++) {
		L1.push_back(i+1);
	}
	
	list<int>::iterator it = L1.end()--;
	while (N--) {
		for (int k = K; k > 0; k--) {
			if (++it == L1.end()) {
				it = L1.begin();
			}
		}
		L2.push_back(*it);
		it = L1.erase(it);
		it--;
	}
	cout << '<';
	for (auto c = L2.begin(); c != L2.end(); c++) {
		if (c == --L2.end()) cout << *c << '>';
		else cout << *c << ", " ;
	}
	
    return 0;
}

