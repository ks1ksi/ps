#include <bits/stdc++.h>


using namespace std;

typedef struct _cow {
    long long height, weight, power;
} Cow;

int N, H;
Cow arr[20];

long long ch[1<<20];
long long cw[1<<20];
long long st[1<<20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }
    
    memset(st, -1, sizeof(st));
    st[0] = LLONG_MAX;
    
    for (int i = 1; i < (1<<N); i++) {
        for (int j = 0 ; j < N; j++) {
            if (i&(1<<j)) {
                ch[i] = ch[i-(1<<j)]+arr[j].height;
                cw[i] = cw[i-(1<<j)]+arr[j].weight;
                st[i] = max(st[i], max(min(st[i-(1<<j)]-arr[j].weight, arr[j].power), min(arr[j].power-cw[i-(1<<j)], st[i-(1<<j)])));
            }
        }
    }
    
    long long ans = -1;
    
    for (int i = 0; i < (1<<N); i++) {
        if (ch[i] >= H) {
            ans = max(ans, st[i]);
        }
    }
    
    if (ans == -1) cout << "Mark is too tall";
    else cout << ans;
    
    return 0;
}