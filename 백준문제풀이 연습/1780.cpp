#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 2190

using namespace std;
int paperValue[3] = { 0,0,0 };
int paper[MAX_SIZE][MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool possible(int weight, int x, int y) {
    int start = paper[x][y];
    for (int i = 0; i < weight; i++) {
        for (int j = 0; j < weight; j++) {
            if (start != paper[x + j][y + i])
                return false;
        }
    }
    return true;
}
void paperCheck(int index, int x, int y) {
    int weight = 1;
    for (int i = 0; i < index; i++)
        weight *= 3;
    if (possible(weight, x, y)) {
        int start = paper[x][y];
        paperValue[start] += 1;
        return;
    }
    else {
        weight /= 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                paperCheck(index - 1, x + j * weight, y + i * weight);
            }
        }
    }
}


int main() {
    init();
    int weight = 0;
    int index = 0;
    cin >> weight;

    for (int i = 1; i <= weight; i++) {
        for (int j = 1; j <= weight; j++) {
            cin >> paper[j][i];
            paper[j][i] += 1;
        }
    }
    while (weight > 1) {
        weight /= 3;
        index += 1;
    }
    paperCheck(index, 1, 1);
    for (int i = 0; i < 3; i++)
        cout << paperValue[i] << " ";

    return 0;
}