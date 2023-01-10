#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	list<char> L = {};
	cin >> s;
	for (auto c : s) {
		L.push_back(c);
	}
	auto it = L.end();
	int n;
	cin >> n;
	while (n--) {
		char cmd;
		cin >> cmd;
		switch (cmd)
		{
			case 'P':
				char ch;
				cin >> ch;
				L.insert(it, ch);
				break;
			case 'L':
				if (it != L.begin()) it--;
				break;
			case 'D':
				if (it != L.end()) it++;
				break;
			case 'B':
				// erase는 삭제에 성공하면 삭제한 요소의 다음 iterator를 반환
				if (it != L.begin()) it = L.erase(--it);
				break;
		}
	}
	for (auto i : L) cout << i;
    return 0;
}

