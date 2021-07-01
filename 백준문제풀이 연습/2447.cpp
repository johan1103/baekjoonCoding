#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 6563

using namespace std;
char star[MAX_SIZE][MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void emptyStar(int n, int x, int y) {
    if (n == 1) {
        star[x][y] = ' ';
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                star[x + j][y + i] = ' ';
        }
    }
}
void starLight(int n, int x, int y) {
    if (n == 1) {
        star[x][y] = '*';
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                emptyStar(n / 3, x + j * n / 3, y + i * n / 3);
            else
                starLight(n / 3, x + j * n / 3, y + i * n / 3);
        }
    }
}


int main() {
    init();
    int n = 0;
    cin >> n;
    starLight(n, 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << star[j][i];
        cout << "\n";
    }
    return 0;
}