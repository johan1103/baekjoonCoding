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
void starLight(int base, int height, int x, int y) {
    if (base == 5) {
        star[x][y] = '*';
        star[x - 1][y + 1] = '*';
        star[x + 1][y + 1] = '*';
        for (int i = -2; i <= 2; i++)
            star[x + i][y + 2] = '*';
        return;
    }
    int nextBase = (base - 1) / 2;
    int nextHeight = height / 2;
    starLight(nextBase, nextHeight, x, y);
    starLight(nextBase, nextHeight, x - (nextBase + 1) / 2, y + nextHeight);
    starLight(nextBase, nextHeight, x + (nextBase + 1) / 2, y + nextHeight);
}


int main() {
    init();
    int n = 0;
    cin >> n;
    n *= 2;
    for (int i = 0; i <= n / 2; i++)
        for (int j = 0; j <= n; j++)
            star[j][i] = ' ';
    int startX = n / 2;
    int base = n - 1;
    int height = 1;
    starLight(base, n / 2, startX, 1);
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= n; j++)
            cout << star[j][i];
        cout << "\n";
    }

    return 0;
}