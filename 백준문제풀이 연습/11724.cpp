#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

int n, m, start;
int map[1001][1001];
int visit[1001];
queue<int> q;

void dfs(int start) {
    visit[start] = 1;
    for (int i = 1; i <= n; i++) {
        if (map[start][i] == 1 && visit[i] == 0) {
            dfs(i);
        }
    }
}

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}


int main() {
    init();
    cin >> n >> m;
    int a, b;
    int count = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            count += 1;
            dfs(i);
        }
    }
    cout << count << "\n";
    return 0;
}
