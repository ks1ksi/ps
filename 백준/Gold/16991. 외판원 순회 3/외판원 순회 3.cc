#include <bits/stdc++.h>

using namespace std;

const double INF = 987654321.0;
int N;
pair<int, int> arr[16];
double cache[16][1<<16];

double get_dist(pair<int, int> p1, pair<int, int> p2) {
	int y1 = p1.first;
	int x1 = p1.second;
	int y2 = p2.first;
	int x2 = p2.second;
	
	return sqrt(pow(y1-y2, 2) + pow(x1-x2, 2));
}

double solve(int now, int cur) {
	if (cur == (1<<N)-1) {
		return get_dist(arr[now], arr[0]);
	}
	
	double& ret = cache[now][cur];
	if (ret != 0) return ret;
	
	ret = INF;
	for (int i = 1; i < N; i++) {
		if (cur&(1<<i)) continue;
		ret = min(ret, solve(i, cur|(1<<i)) + get_dist(arr[now], arr[i]));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int y, x;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		arr[i] = {y, x};
	}
	
	cout << fixed;
	//cout.precision(6);
	
	memset(cache, 0, sizeof(cache));
	cout << solve(0, 1);
	return 0;
}