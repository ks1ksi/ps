#include <string>
#include <vector>

using namespace std;

int rotate(int r1, int c1, int r2, int c2, vector<vector<int>>& v) {
    int ret = 1e9;
    
    int next = v[r1][c1];
    for (int c = c1+1; c <= c2; c++) {
        ret = min(ret, next);
        int tmp = v[r1][c];
        v[r1][c] = next;
        next = tmp;
    }
    for (int r = r1+1; r <= r2; r++) {
        ret = min(ret, next);
        int tmp = v[r][c2];
        v[r][c2] = next;
        next = tmp;
    }
    for (int c = c2-1; c >= c1; c--) {
        ret = min(ret, next);
        int tmp = v[r2][c];
        v[r2][c] = next;
        next = tmp;
    }
    for (int r = r2-1; r >= r1; r--) {
        ret = min(ret, next);
        int tmp = v[r][c1];
        v[r][c1] = next;
        next = tmp;
    }
    ret = min(ret, next);
    return ret;
}

vector<int> solution(int r, int c, vector<vector<int>> q) {
    vector<int> ans;
    vector<vector<int>> v(r, vector<int>(c));
    int x = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            v[i][j] = x++;
        }
    }
    
    for (auto& qr : q) {
        ans.emplace_back(rotate(qr[0]-1, qr[1]-1, qr[2]-1, qr[3]-1, v));
    }
    
    return ans;
}