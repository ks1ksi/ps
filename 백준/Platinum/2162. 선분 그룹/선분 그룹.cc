#include <bits/stdc++.h>

using namespace std;

int N;
int p[3000];

pair<pair<int, int>, pair<int, int>> arr[3000];

int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void Union(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    p[n1] += p[n2];
    p[n2] = n1;
}

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = p2.first;
    int y2 = p2.second;
    
    int x3 = p3.first;
    int y3 = p3.second;
    
    int temp = x1*y2+x2*y3+x3*y1;
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

bool is_intersect(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4) {
    int ccw1 = ccw(p1, p2, p3);
    int ccw2 = ccw(p1, p2, p4);
    int ccw3 = ccw(p3, p4, p1);
    int ccw4 = ccw(p3, p4, p2);
    
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
    return (s1&&s2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int x1, y1, x2, y2;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        arr[i] = {{x1, y1}, {x2, y2}};
    }
    
    memset(p, -1, sizeof(p));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (is_intersect(arr[i].first, arr[i].second, arr[j].first, arr[j].second)) {
                Union(i, j);
            }
        }
    }
    
    int gcnt = 0, lcnt = 1;
    for (int i = 0; i < N; i++) {
        if (p[i] < 0) gcnt++;
        lcnt = min(lcnt, p[i]);
    }
    cout << gcnt << '\n' << -lcnt;
    return 0;
}