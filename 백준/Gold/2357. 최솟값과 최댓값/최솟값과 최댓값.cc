#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100000];
vector<int> minv;
vector<int> maxv;

int init(int* arr, vector<int>& v, int start, int end, int node, bool ismin) {
    if (start == end) {
        return v[node] = arr[start];
    }
    if (ismin) {
        return v[node] = min(init(arr, v, start, (start+end)/2, node*2, ismin), init(arr, v, (start+end)/2+1, end, node*2+1, ismin));
    }
    else {
        return v[node] = max(init(arr, v, start, (start+end)/2, node*2, ismin), init(arr, v, (start+end)/2+1, end, node*2+1, ismin));
    }
}

int getm(int* arr, vector<int>& v, int start, int end, int node, int left, int right, bool ismin) {
    if (left > end || right  < start) {
        if (ismin) return INT_MAX;
        else return INT_MIN;
    }
    else if (left <= start && end <= right) {
        return v[node];
    }
    else {
        if (ismin) {
            return min(getm(arr, v, start, (start+end)/2, node*2, left, right, ismin), getm(arr, v, (start+end)/2+1, end, node*2+1, left, right, ismin));
        }
        else {
            return max(getm(arr, v, start, (start+end)/2, node*2, left, right, ismin), getm(arr, v, (start+end)/2+1, end, node*2+1, left, right, ismin));            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int h = (int)ceil(log2(N));
    int size = (1<<h+1);
    minv.resize(size);
    maxv.resize(size);

    init(arr, minv, 0, N-1, 1, true);
    init(arr, maxv, 0, N-1, 1, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << getm(arr, minv, 0, N-1, 1, a-1, b-1, true) << ' ' << getm(arr, maxv, 0, N-1, 1, a-1, b-1, false) << '\n';
    }

    return 0;
}