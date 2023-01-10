#include <bits/stdc++.h>

using namespace std;

int N;
int prob[100][100];
double cache[1<<20];

double solve(int jimmy, int mission) {
    if (mission == (1<<N)-1) {
        return 1;
    }
    
    double& ret = cache[mission];
    if (ret != 0) return ret;
    
    ret = 0;
    for (int i = 0; i < N; i++) {
        if (mission&(1<<i)) continue;
        double tmp = solve(jimmy+1, mission|(1<<i))*prob[jimmy][i];
        ret = max(ret, tmp);
    }
    return ret;
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> prob[i][j];
        }
    }
    cout << fixed;
    cout.precision(6);
    cout << solve(0, 0)/pow(100, N-1);
    return 0;
}