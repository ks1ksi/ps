#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		list<char> L = {};
		auto it = L.begin();
		for (auto c : s) {
			switch (c)
			{
				case '<':
					if (it != L.begin()) it--;
					break;
				case '>':
					if (it != L.end()) it++;
					break;
				case '-':
					if (it != L.begin()) it = L.erase(--it);
					break;
				default:
					L.insert(it, c);
			}
		}
		for (auto i : L) cout << i;
		cout << '\n';
	}
    return 0;
}

