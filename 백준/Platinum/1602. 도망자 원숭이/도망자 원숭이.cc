#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9, MAX = 500;
int N, M, Q;
pair<int, int> graph[MAX][MAX]; // cost, delay
int max_d[MAX][MAX];
vector<pair<int, int>> delay, sorted_delay; // delay, idx

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> Q;

    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        delay.push_back({d, i});
    }

    sorted_delay = vector<pair<int, int>>(N);
    copy(delay.begin(), delay.end(), sorted_delay.begin());
    sort(sorted_delay.begin(), sorted_delay.end());

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = max(delay[a-1].first, delay[b-1].first);
        graph[a-1][b-1] = {c, d};
        graph[b-1][a-1] = {c, d};
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!graph[i][j].first) {
                graph[i][j] = {INF, max(delay[i].first, delay[j].first)};
            }
        }
    }

    for (int k = 0; k < N; k++) {
        int d = sorted_delay[k].first;
        int n = sorted_delay[k].second;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int md = max(graph[i][j].second, d);
                if (graph[i][j].first+graph[i][j].second > graph[i][n].first+graph[n][j].first+md) {
                    graph[i][j].first = graph[i][n].first+graph[n][j].first;
                    graph[i][j].second = md;
                }
            }
        }
    }

    while (Q--) {
        int s, t;
        cin >> s >> t;
        if (graph[s-1][t-1].first == INF) cout << -1 << '\n';
        else cout << graph[s-1][t-1].first+graph[s-1][t-1].second << '\n';
    }

    return 0;
}