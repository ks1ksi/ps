#include <bits/stdc++.h>

using namespace std;

int C, N, ANS;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
multiset<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> N;
    for (int i = 0; i < C; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({b, a});
    }
    
    while (!pq.empty()) {
        int start = pq.top().second;
        int end = pq.top().first;
        auto iter = s.lower_bound(start);
        if (iter != s.end() && (*iter) <= end) {
            ANS++;
            s.erase(iter);
        }
        pq.pop();
    }
    
    cout << ANS;    
    return 0;
}