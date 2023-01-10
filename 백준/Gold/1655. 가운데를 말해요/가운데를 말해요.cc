#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, x;
    priority_queue<int> pqM; //max
    priority_queue<int, vector<int>, greater<int>> pqm; //min
    
    cin >> M;
    cin >> x;
    pqM.push(x);
    cout << x << '\n';
    
    for (int i = 1; i < M; i++) {
        cin >> x;
        if (x > pqM.top()) pqm.push(x);
        else pqM.push(x);
        
        if (pqM.size() < pqm.size()) {
            while (pqM.size() < pqm.size()) {
                pqM.push(pqm.top());
                pqm.pop();
            }
        }
        else { // M >= m
            while (pqM.size() > pqm.size()+1) {
                pqm.push(pqM.top());
                pqM.pop();
            }
        }
        cout << pqM.top() << '\n';
    }
    return 0;
}