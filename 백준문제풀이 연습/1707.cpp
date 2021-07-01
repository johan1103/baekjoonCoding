#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 20000+4

using namespace std;

vector<int> map[MAX_SIZE];
int visit[MAX_SIZE];
int m = 0, n = 0;

void dfs(int start) {
    for (int i = 0; i < map[start].size(); i++) {
        int nextNode = map[start][i];
        if (visit[nextNode] == 0) {
            if (visit[start] == 1)
                visit[nextNode] = 2;
            else
                visit[nextNode] = 1;
            dfs(nextNode);
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= m; i++) {
        int mapSize = map[i].size();
        for (int j = 0; j < mapSize; j++) {
            int next = map[i][j];
            if (visit[i] == visit[next])
                return 0;
        }
    }
    return 1;
}


void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}


int main() {
    init();
    int a, b;
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n;
        for (int j = 1; j <= n; j++) {
            cin >> a >> b;
            map[a].push_back(b);
            map[b].push_back(a);
        }
        for (int j = 1; j <= m; j++) {
            if (visit[j] == 0) {
                visit[j] = 1;
                dfs(j);
            }
        }
        if (isBipartiteGraph()) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
        for (int j = 1; j <= m; j++)
            map[j].clear();
        memset(visit, false, sizeof(visit));
    }
    return 0;
}
