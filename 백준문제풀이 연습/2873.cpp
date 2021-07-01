#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 1004

using namespace std;
int map[MAX_SIZE][MAX_SIZE];
int height = 0, weight = 0;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void route(int x) {
    if (x == 1) {
        for (int i = 0; i < weight - 1; i++)
            cout << "R";
        cout << "D";
        for (int i = 0; i < weight - 1; i++)
            cout << "L";
    }
    else {
        for (int i = 0; i < weight - 1; i++)
            cout << "L";
        cout << "D";
        for (int i = 0; i < weight - 1; i++)
            cout << "R";
    }
}
void specialRoute(int x, int nx) {
    if (x == weight)
    {
        cout << "D";
        return;
    }
    if (x + 1 == nx) {
        if (nx == weight) {
            cout << "DR";
            return;
        }
        cout << "DRRUR";
        specialRoute(x + 3, nx);
    }
    else if (x == nx) {
        cout << "R";
        specialRoute(x + 1, nx);
    }
    else {
        cout << "DRUR";
        specialRoute(x + 2, nx);
    }
}

int main() {
    init();
    cin >> height >> weight;
    int minValue = MAX_SIZE;
    pair<int, int> locate;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= weight; j++) {
            cin >> map[j][i];
            if (map[j][i] < minValue && (i + j) % 2 == 1) {
                minValue = map[j][i];
                locate.first = j;
                locate.second = i;
            }
        }
    }
    int next = 1;
    if (weight % 2 == 0 && height % 2 == 0) {
        for (int i = 1; i <= height; i += 2) {
            if (locate.second == i || locate.second == i + 1) {
                specialRoute(1, locate.first);
                next = weight;
                if (i + 1 != height)
                    cout << "D";
            }
            else {
                route(next);
                if (i + 1 != height)
                    cout << "D";
            }
        }
    }
    else if (height % 2 == 1) {
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= weight - 1; j++) {
                if (next == 1) {
                    cout << "R";
                }
                else {
                    cout << "L";
                }
            }
            if (next == 1)
                next = weight;
            else
                next = 1;
            if (i != height)
                cout << "D";
        }
    }
    else if (weight % 2 == 1) {
        for (int i = 1; i <= weight; i++) {
            for (int j = 1; j <= height - 1; j++) {
                if (next == 1) {
                    cout << "D";
                }
                else {
                    cout << "U";
                }
            }
            if (next == 1)
                next = height;
            else
                next = 1;
            if (i != weight)
                cout << "R";
        }
    }
    return 0;
}