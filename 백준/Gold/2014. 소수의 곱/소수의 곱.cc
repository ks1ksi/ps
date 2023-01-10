#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> num;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    int x;
    for (int i = 0; i < K; i++) {
        cin >> x;
        num.push_back(x);
        pq.push(x);
    }

    while (N>1) {
        int last = pq.top();
        while (!pq.empty() && pq.top() == last) {
            pq.pop();
        }
        N--;
        for (auto i = num.begin(); i != num.end(); i++) {
            if (1LL * last * (*i) > INT_MAX){
                continue;
            }
            else {
                pq.push(last * (*i));                
            }
        }     
    }
    cout << pq.top();
    return 0;
}