#include <bits/stdc++.h>

using namespace std;

int arr[9][9];
bool r_check[9][10];
bool c_check[9][10];
bool s_check[3][3][10];
bool SW = false;
vector<pair<int, int>> v;

void solve(vector<pair<int, int>>::iterator iter) {
    if (SW) return;
    if (iter == v.end()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j];
            }
            cout << '\n';
        }
        SW = true;
        return;
    }
    
    int y = (*iter).first;
    int x = (*iter).second;
    
    for (int i = 0; i < 9; i++) {
        if (r_check[y][i+1]) continue;
        if (c_check[x][i+1]) continue;
        if (s_check[y/3][x/3][i+1]) continue;
        
        arr[y][x] = i+1;
        r_check[y][i+1] = true;
        c_check[x][i+1] = true;
        s_check[y/3][x/3][i+1] = true;
        
        solve(iter+1);
        
        arr[y][x] = 0;
        r_check[y][i+1] = false;
        c_check[x][i+1] = false;
        s_check[y/3][x/3][i+1] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    int x;
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> c;
            x = c - '0';
            if (x == 0) {
                v.push_back({i, j});
            }
            else {
                arr[i][j] = x;
                r_check[i][x] = true;
                c_check[j][x] = true;
                s_check[i/3][j/3][x] = true;
            }
        }
    }
    vector<pair<int, int>>::iterator iter = v.begin();
    solve(iter);
    return 0;
}