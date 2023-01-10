#include <bits/stdc++.h>

using namespace std;

constexpr double INF = 2e9;
vector<pair<double, double>> cannon;
pair<double, double> start, dest;
int N;
double table[102][102];
double time_s[102];
bool visited[102];

double get_dist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p1.first-p2.first, 2)+pow(p1.second-p2.second, 2));
}

void dijkstra() {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 0});
    for (int i = 1; i <= N+1; i++) {
        time_s[i] = INF;
    }
    while (!pq.empty()) {
        double cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (int i = 0; i <= N+1; i++) {
            if (cur == i || visited[i]) continue;
            if (time_s[i] > time_s[cur] + table[cur][i]) {
                time_s[i] = time_s[cur] + table[cur][i];
                pq.push({cost+table[cur][i], i});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> start.first >> start.second;
    cin >> dest.first >> dest.second;
    cin >> N;
    cannon = vector<pair<double, double>>(N);
    for (int i = 0; i < N; i++) {
        cin >> cannon[i].first >> cannon[i].second;
    }

    double d = get_dist(start, dest);
    table[0][N+1] = d/5;
    table[N+1][0] = table[0][N+1];

    for (int i = 0; i < N; i++) {
        d = get_dist(start, cannon[i]);
        table[0][i+1] = d/5;
        table[i+1][0] = table[0][i+1];
    }
    for (int i = 0; i < N; i++) {
        d = get_dist(dest, cannon[i]);
        table[N+1][i+1] = d > 30 ? abs(50-d)/5 + 2 : d/5;
        table[i+1][N+1] = table[N+1][i+1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (i == j) continue;
            d = get_dist(cannon[i], cannon[j]);
            table[i+1][j+1] = d > 30 ? abs(50-d)/5 + 2 : d/5;
            table[j+1][i+1] = table[i+1][j+1];
        }
    }
    dijkstra();
    cout << time_s[N+1];
    return 0;
}