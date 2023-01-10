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
    
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    int ccw1 = ccw(x1, y1, x2, y2, x3, y3);
    int ccw2 = ccw(x1, y1, x2, y2, x4, y4);
    int ccw3 = ccw(x3, y3, x4, y4, x1, y1);
    int ccw4 = ccw(x3, y3, x4, y4, x2, y2);
    
    pair<long long, long long> p1 = {x1, y1};
    pair<long long, long long> p2 = {x2, y2};
    pair<long long, long long> p3 = {x3, y3};
    pair<long long, long long> p4 = {x4, y4};
    
    bool s1 = (ccw1*ccw2<=0);
    bool s2 = (ccw3*ccw4<=0);
        
    if (ccw1*ccw2 == 0 && ccw3*ccw4 == 0) {
        if (p1 > p2) {
            swap(p1, p2);
        }
        if (p3 > p4) {
            swap(p3, p4);
        }
        if (p2 < p3 || p1 > p4) {
            s1 = false;
        }
    }
    cout << (s1&&s2);
    return 0;
}