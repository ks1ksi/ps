#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1001;
int N;
stack<int> adj[MAX];
int edges[MAX][MAX];
bool visited_n[MAX];
int degree[MAX];

void euler(int n) {
    while (!adj[n].empty()) {
        int next = adj[n].top();
        adj[n].pop();
        if (edges[n][next] && edges[next][n]) {
            edges[n][next]--;
            edges[next][n]--;
            euler(next);
        }
    }
    cout << n << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < N+1; j++) {
            int x;
            cin >> x;
            while (x--) {
                adj[i].push(j);
                edges[i][j]++;
                degree[j]++;
            }
        }
    }
    // 간선 홀수개 있으면 오일러 회로 완성 불가
    for (int i = 1; i < N+1; i++) {
        if (degree[i]%2) {
            cout << -1;
            return 0;
        }
    }

    euler(1);

    return 0;
}