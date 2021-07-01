#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 100004

using namespace std;

vector<pair<int, int>> map[MAX_SIZE];
int visit[MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void treeDfs(int start) {
    int next = 0;
    for (int i = 0; i < map[start].size(); i++) {
        next = map[start][i].first;
        if (visit[next] != 0)
            continue;
        else {
            visit[next] = visit[start] + map[start][i].second;
            treeDfs(next);
        }
    }
}

int main() {
    init();
    int n = 0;
    int now, next, leng = 0;
    pair<int, int> temp;
    cin >> n;
    // 맵 입력
    for (int i = 0; i < n - 1; i++) {
        cin >> now >> next >> leng;
        temp.first = next;
        temp.second = leng;
        map[now].push_back(temp);
        temp.first = now;
        map[next].push_back(temp);
    }
    //가장 긴 리프노드,길이 찾기 & 다음 dfs를 위해 초기화
    treeDfs(1);
    int maxLeng = 0;
    int maxLiff = 0;
    for (int i = 2; i <= n; i++) {
        if (visit[i] > maxLeng) {
            maxLiff = i;
            maxLeng = visit[i];
        }
    }
    memset(visit, 0, sizeof(visit));
    maxLeng = 0;
    //그 다음으로 긴 리프길이 찾기
        // ***** visit을 거리처럼 이용할때 주의점. 시작점의 visit이 0이라 방문 안한줄알고 다시 돌아와 탐색함
    treeDfs(maxLiff);
    for (int i = 1; i <= n; i++) {
        if (i == maxLiff)
            continue;
        maxLeng = max(maxLeng, visit[i]);
    }
    cout << maxLeng;
    return 0;
}
