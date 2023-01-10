#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // max->f start->s destination->g
    int f, s, g, u, d;
    queue<int> q;
    cin >> f >> s >> g >> u >> d;
    int elev[f+1] = {};
    elev[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        if (cur == g) {
            break;
        }
        q.pop();
        if (cur+u <= f && (elev[cur+u] == 0 || elev[cur+u] > elev[cur] + 1)) {
            elev[cur+u] = elev[cur] + 1;
            q.push(cur+u);
        }
        if (cur-d >= 1 && (elev[cur-d] == 0 || elev[cur-d] > elev[cur] + 1)) {
            elev[cur-d] = elev[cur] + 1;
            q.push(cur-d);
        }
    }
    
    if (elev[g] == 0) {
        cout << "use the stairs";
    }
    else {
        cout << elev[g] - 1;
    }
    return 0;
}