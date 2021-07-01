#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 104

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };
queue<pair<int, int>> route;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void bfs(int x, int y) {
    visit[x][y] = 1;
    pair<int, int> start;
    start.first = x;
    start.second = y;
    route.push(start);
    while (!route.empty()) {
        x = route.front().first;
        y = route.front().second;
        route.pop();
        for (int i = 0; i < 4; i++) {
            int nx = 0;
            int ny = 0;
            nx = x + dx[i];
            ny = y + dy[i];
            if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
                pair<int, int> xy;
                xy.first = nx;
                xy.second = ny;
                route.push(xy);
                visit[nx][ny] = visit[x][y] + 1;
            }
        }
    }

}


int main() {
    init();
    int weight = 0, height = 0;
    cin >> height >> weight;
    for (int h = 1; h <= height; h++) {
        string temp;
        cin >> temp;
        for (int i = 0; i < temp.size(); i++) {
            map[i + 1][h] = temp[i] - '0';
        }
    }
    bfs(1, 1);
    cout << visit[weight][height];
    return 0;
}
