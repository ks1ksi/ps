#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int N, K;
int arr[500000], cnt = 0;

void merge(int s, int e, int m) {
    int tmp[e-s+1];
    int i = s, j = m+1, t = 0;
    while (i <= m && j <= e) {
        if (arr[i] < arr[j]) tmp[t++] = arr[i++];
        else tmp[t++] = arr[j++];
    }
    while (i <= m) tmp[t++] = arr[i++];
    while (j <= e) tmp[t++] = arr[j++];
    for (int idx = 0; idx < e-s+1; idx++) {
        arr[idx+s] = tmp[idx];
        cnt++;
        if (cnt == K) cout << tmp[idx];
    }
}

void merge_sort(int s, int e) {
    if (s >= e) return;
    int m = (s + e) / 2;
    merge_sort(s, m);
    merge_sort(m+1, e);
    merge(s, e, m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    merge_sort(0, N-1);
    if (cnt < K) cout << -1;

    return 0;
}