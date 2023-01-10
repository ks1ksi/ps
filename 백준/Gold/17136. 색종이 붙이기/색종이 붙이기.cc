#include <bits/stdc++.h>

using namespace std;

bool arr[10][10];
int paper[5] = {5, 5, 5, 5, 5};
int space = 0;
int MIN = INT_MAX;
vector<pair<int, int>> v;
vector<pair<int,int>>::iterator iter;

bool check_safe(int y, int x) {
    return y >= 0 && y < 10 && x >= 0 && x < 10;
}

void cover(int y, int x, int size, bool value) {
    for (int i = y; i < y+size; i++) {
        for (int j = x; j < x+size; j++) {
            arr[i][j] = value;
        }
    }
    if (value) { // uncover
        space += (size*size);
        paper[size-1] += 1;
    }
    else { // cover
        space -= (size*size);
        paper[size-1] -= 1;
    }
}

bool check(int y, int x, int size) {
    if (!check_safe(y+size-1, x+size-1)) return false;
    if (paper[size-1] <= 0) return false;
    for (int i = y; i < y+size; i++) {
        for (int j = x; j < x+size; j++) {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

void solve(int cnt) {
    if (space == 0) {
        MIN = min(MIN, cnt);
        return;
    }
    
    int y = (*iter).first;
    int x = (*iter).second;
    int idx = 0;
    while (!arr[y][x]) {
        iter++;
        idx++;
        y = (*iter).first;
        x = (*iter).second;
    }
    
    for (int i = 1; i <= 5; i++) {
        if (check(y, x, i)) {
            cover(y, x, i, 0);
            iter++;
            solve(cnt+1);
            cover(y, x, i, 1);
            iter--;                
        }
    }
    iter -= idx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == true) {
                space++;
                v.push_back({i, j});
            }
        }
    }
    
    iter = v.begin();
    solve(0);
    
    if (MIN == INT_MAX) {
        if (space) cout << -1;
        else cout << 0;
    }
    else {
        cout << MIN;
    }
    
    return 0;
}