#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 100004

using namespace std;

vector<int> map[MAX_SIZE];
int parentNode[MAX_SIZE];
int visit[MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void treeDfs(int start) {
    int next = 0;
    visit[start] = 1;
    for (int i = 0; i < map[start].size(); i++) {
        next = map[start][i];
        if (visit[next] == 1)
            continue;
        else {
            parentNode[next] = start;
            treeDfs(next);
        }
    }
}

int main() {
    init();
    int n = 0;
    cin >> n;
    int parent = 0, child = 0;
    for (int i = 1; i < n; i++) {
        cin >> parent >> child;
        map[parent].push_back(child);
        map[child].push_back(parent);
    }
    treeDfs(1);
    for (int i = 2; i <= n; i++)
        cout << parentNode[i] << "\n";

    return 0;
}
