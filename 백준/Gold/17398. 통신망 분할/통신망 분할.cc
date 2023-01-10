#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int p[100001];
pair<int, int> arr[100000];
pair<int, int> start[100000];
vector<int> v;

int find(int n) {
    if (p[n] <= 0) return n;
    return p[n] = find(p[n]);
}

void Union(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    else {
        p[n1] += p[n2];
        p[n2] = n1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, a;
    cin >> N >> M >> Q;
    for (int i =0 ; i < M; i++) {
        cin >> x >> y;
        arr[i] = {x, y};
        start[i] = {x, y};
    }
    for (int i = 0; i < Q; i++) {
        cin >> a;
        v.push_back(a-1);
        start[a-1] = {-1, -1};
    }
    
    memset(p, -1, sizeof(p));
    for (int i = 0; i < M; i++) {
        if (start[i].first == -1) continue;
        Union(arr[i].first, arr[i].second);
    }

    long long ans = 0;
    for (auto iter = v.rbegin(); iter != v.rend(); iter++) {
        if (find(arr[*iter].first) != find(arr[*iter].second)) {
            ans += p[find(arr[*iter].first)]*p[find(arr[*iter].second)];
        }
        Union(arr[*iter].first, arr[*iter].second);
    }
    cout << ans;
    return 0;
}