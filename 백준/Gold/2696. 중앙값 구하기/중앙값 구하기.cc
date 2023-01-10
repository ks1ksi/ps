#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int M, x;
        priority_queue<int> pqM; //max
        priority_queue<int, vector<int>, greater<int>> pqm; //min
        
        cin >> M;
        cout << M/2+1 << '\n';
        cin >> x;
        pqM.push(x);
        cout << x << ' ';
        
        for (int i = 1; i < M; i++) {
            cin >> x;
            if (x > pqM.top()) pqm.push(x);
            else pqM.push(x);
            
            if (i%2 == 0) {
                if (pqM.size() >= pqm.size()) {
                    while (pqm.size()-pqM.size() != 1) {
                        pqm.push(pqM.top());
                        pqM.pop();
                    }
                }
                else {
                    while (pqm.size()-pqM.size() != 1) {
                        pqM.push(pqm.top());
                        pqm.pop();
                    }
                }
                if (i%20 == 0) cout << '\n';
                cout << pqm.top() << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}