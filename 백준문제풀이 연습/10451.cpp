#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 1000+4

using namespace std;

int map[MAX_SIZE];
int visit[MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void dfs(int start) {
    visit[start] = 1;
    int next = map[start];
    if (visit[next] != 0)
        return;
    dfs(next);
    return;
}

int main() {
    init();
    int t = 0;
    int n = 0;
    int cnt = 0;
    cin >> t;
    for (int time = 0; time < t; time++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> map[i];
        for (int i = 1; i <= n; i++) {
            if (visit[i] != 0)
                continue;
            dfs(i);
            cnt += 1;
        }
        cout << cnt << "\n";
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        cnt = 0;
    }
    return 0;
}
