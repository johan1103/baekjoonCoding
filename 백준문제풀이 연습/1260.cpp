#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

int n, m, start;
int A[1001][1001];
int visit[1001];
queue<int> q;

void dfs(int start);
void bfs(int start);

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}


int main() {
    init();
    cin >> n >> m >> start;
    memset(A, 0, sizeof(A));
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
        A[b][a] = 1;
    }
    dfs(start);
    cout << "\n";
    memset(visit, 0, sizeof(visit));
    bfs(start);
    cout << "\n";
    return 0;
}


void dfs(int start) {
    cout << start << " ";
    visit[start] = 1;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0 && A[start][i] == 1)
            dfs(i);
    }
}

void bfs(int start) {
    visit[start] = 1;
    q.push(start);
    while (!q.empty()) {
        start = q.front();
        q.pop();
        cout << start << " ";
        for (int i = 1; i <= n; i++) {
            if (A[start][i] == 1 && visit[i] == 0) {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}