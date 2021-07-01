#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 500

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
int villageCnt[MAX_SIZE];
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y, int n) {
    villageCnt[n] += 1;
    visit[x][y] = n;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
            dfs(nx, ny, n);
        }
    }
}

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    init();
    int n = 0;
    cin >> n;
    // 지도 입력
    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            map[j + 1][i] = temp[j] - '0';
        }
    }
    //dfs
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visit[j][i] == 0 && map[j][i] == 1) {
                cnt += 1;
                dfs(j, i, cnt);
            }
        }
    }
    //오름차순 정렬
    sort(villageCnt + 1, villageCnt + cnt + 1);
    //정답 출력
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        cout << villageCnt[i] << "\n";
    }

    return 0;
}
