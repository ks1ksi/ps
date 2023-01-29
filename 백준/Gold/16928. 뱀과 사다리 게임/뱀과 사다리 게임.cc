#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> board(101);
bool visited[101];

int bfs() {
    queue<pair<int, int>> q;
    q.emplace(1, 0); 
    visited[1] = 1;
    while (q.size()) {
        auto [cur, cnt] = q.front();
        q.pop();
        if (cur == 100) return cnt;
        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (board[next] && !visited[board[next]]) {
                visited[board[next]] = 1;
                q.emplace(board[next], cnt + 1);
            }
            else if (!board[next] && !visited[next]) {
                visited[next] = 1;
                q.emplace(next, cnt + 1);
            }
        }        
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int a, b;
        cin >> a >> b;
        board[a] = b;
    }

    cout << bfs() << '\n';

    return 0;
}