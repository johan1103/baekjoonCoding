#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_VALUE 10000004
using namespace std;
int map[14][14];
int visit[14];
int n = 0;
int startLine = 0;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool visitAll() {
    for (int i = 0; i < n; i++) {
        if (visit[i] != 1)
            return false;
    }
    return true;
}
int tsp(int start) {
    visit[start] = 1;
    int result = MAX_VALUE;
    int next = 0;
    if (visitAll()) {
        visit[start] = 0;
        if (map[start][startLine] != 0)
            return map[start][startLine];
        else
            return MAX_VALUE;
    }
    for (int i = 0; i < n; i++) {
        if (map[start][i] != 0 && visit[i] == 0) {
            next = i;
            result = min(result, tsp(next) + map[start][i]);
        }
    }
    visit[start] = 0;
    return result;
}

int main() {
    init();
    memset(visit, 0, sizeof(visit));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
    cout << tsp(0);
    return 0;
}