#include <string>
#include <vector>
#include <cstring>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

const int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int p[100000], N;

int find (int a) {
    if (p[a] < 0) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    p[a] += p[b];
    p[b] = a;
}

int solution(vector<vector<int>> land, int height) {
    memset(p, -1, sizeof(p));
    N = land.size();
    
    // i*N + j;
    // cost, from to
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int node = i*N + j;
            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d], nx = j + dx[d];
                int nnode = ny*N + nx;
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (abs(land[ny][nx] - land[i][j]) > height) {
                    v.emplace_back(abs(land[ny][nx] - land[i][j]), node, nnode);
                }
                else {
                    merge(node, nnode);
                }
            }
        }
    }
    
    sort(v.begin(), v.end());
    int ans = 0;
    for (auto& [cost, a, b] : v) {
        if (find(a) != find(b)) {
            ans += cost;
            merge(a, b);
        }
        if (p[0] == -N*N) break;
    }
    
    return ans;
}