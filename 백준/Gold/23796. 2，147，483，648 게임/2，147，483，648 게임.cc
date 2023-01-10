#include <bits/stdc++.h>

using namespace std;

#define int long long

int arr[8][8];
char W;

void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void push() { // l push
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (!arr[i][j]) {
                int cur = j;
                while (cur < 8 && !arr[i][cur]) cur++;
                if (cur == 8) break;
                while (!arr[i][j]) {
                    for (int k = j; k < 7; k++) {
                        swap(arr[i][k], arr[i][k+1]);
                    }
                }
            }
            if (!arr[i][j+1]) {
                int cur = j+1;
                while (cur < 8 && !arr[i][cur]) cur++;
                if (cur == 8) break;
                while (!arr[i][j+1]) {
                    for (int k = j+1; k < 7; k++) {
                        swap(arr[i][k], arr[i][k+1]);
                    }
                }
            }
            if (arr[i][j] == arr[i][j+1]) {
                arr[i][j] *= 2;
                arr[i][j+1] = 0;
                int idx = j+1;
                while (idx != 7) {
                    swap(arr[i][idx], arr[i][idx+1]);
                    idx++;
                }
            }
        }
    }
}

void rotate(int t) {
    int newarr[8][8] = {0};
    while (t--) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                newarr[j][7-i] = arr[i][j];
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                arr[i][j] = newarr[i][j];
            }
        }  
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> W;

    if (W == 'L') {
        push();
    }
    else if (W == 'R') {
        rotate(2);
        push();
        rotate(2);
    }
    else if (W == 'U') {
        rotate(3);
        push();
        rotate(1);
    }
    else if (W == 'D') {
        rotate(1);
        push();
        rotate(3);
    }
    print_board();
    return 0;
}