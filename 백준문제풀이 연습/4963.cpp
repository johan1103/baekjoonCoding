#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 52

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
const int dy[8] = { -1,-1,0,1,1,1,0,-1 };

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void dfs(int x, int y) {
    visit[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visit[nx][ny] == 0 && map[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}


int main() {
    init();
    int w = 0, h = 0;
    cin >> w >> h;
    while (w != 0 && h != 0) {
        //맵 입력
        for (int height = 1; height <= h; height++) {
            for (int weight = 1; weight <= w; weight++) {
                cin >> map[weight][height];
            }
        }
        //탐색 시작
        int cnt = 0;
        for (int height = 1; height <= h; height++) {
            for (int weight = 1; weight <= w; weight++) {
                if (visit[weight][height] == 1 || map[weight][height] == 0)
                    continue;
                else {
                    dfs(weight, height);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        //문제끝, 초기화,다음 좌표 입력
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        cin >> w >> h;
    }
    return 0;
}
