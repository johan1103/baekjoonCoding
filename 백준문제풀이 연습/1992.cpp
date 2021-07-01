#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 80

using namespace std;
int screen[MAX_SIZE][MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool possible(int index, int x, int y, int value) {
    for (int i = y; i < y + index; i++) {
        for (int j = x; j < x + index; j++) {
            if (screen[j][i] != value)
                return false;
        }
    }
    return true;
}
void quadTree(int n, int x, int y) {
    int start = screen[x][y];
    if (n == 0) {
        cout << "find";
        return;
    }
    if (!possible(n, x, y, start)) {
        cout << "(";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                quadTree(n / 2, x + j * (n / 2), y + i * (n / 2));
            }
        }
        cout << ")";
    }
    else {
        cout << start;
    }
}


int main() {
    init();
    string sen;
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sen;
        for (int j = 0; j < sen.size(); j++) {
            screen[j + 1][i] = sen[j] - '0';
        }
    }
    quadTree(n, 1, 1);

    return 0;
}