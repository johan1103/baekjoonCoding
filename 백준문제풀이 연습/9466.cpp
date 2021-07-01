#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 300000

using namespace std;

int map[MAX_SIZE];
int visit[MAX_SIZE];
int solo[MAX_SIZE];
vector<int> cyclePoint;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void dfs(int start, int n) {
    visit[start] = n;
    int next = map[start];
    if (visit[next] == n) {
        cyclePoint.push_back(next);
        return;
    }
    else if (visit[next] != 0)
        return;
    else
        dfs(next, n);
}
void checkSolo(int start) {
    solo[start] = 1;
    int next = map[start];
    if (solo[next] == 1)
        return;
    else
        checkSolo(next);
}

int main() {
    init();

    int testCase = 0;
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        int n = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> map[i];
        }
        for (int i = 1; i <= n; i++) {
            if (visit[i] != 0)
                continue;
            else
                dfs(i, i);
        }
        for (int i = 0; i < cyclePoint.size(); i++) {
            checkSolo(cyclePoint[i]);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (solo[i] == 0)
                cnt++;
        }
        cout << cnt << "\n";
        //end
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        memset(solo, 0, sizeof(solo));
        cyclePoint.clear();
    }
    return 0;
}
