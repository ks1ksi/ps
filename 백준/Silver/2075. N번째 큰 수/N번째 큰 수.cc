#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            pq.push(x);
        }
        while (pq.size() != N) {
            pq.pop();
        }
    }
    cout << pq.top();    
    return 0;
}