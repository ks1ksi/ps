#include <bits/stdc++.h>

using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long temp = x1*y2+x2*y3+x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    if (temp > 0) {
        return 1;
    } 
    else if (temp < 0) {
        return -1;
    } 
    else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    cout << ccw(x1, y1, x2, y2, x3,y3);
    
    return 0;
}