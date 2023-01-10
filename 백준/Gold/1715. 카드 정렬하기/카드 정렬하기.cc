#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        pq.push(x);
    }
    
    while (!(pq.size() == 1)) {
        int card1 = pq.top();
        pq.pop();
        int card2 = pq.top();
        pq.pop();
        ans += card1+card2;
        pq.push(card1+card2);
    }
    cout << ans;
    return 0;
}