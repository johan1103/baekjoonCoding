#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_VALUE 200004
using namespace std;
int visit[MAX_VALUE];
int destination = 0;
deque<int> map;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void checkMap(int loc) {
    if (loc * 2 <= MAX_VALUE && loc != 0) {
        if (visit[loc * 2] == 0) {
            visit[loc * 2] = visit[loc] + 1;
            map.push_back(loc * 2);
        }
    }
    if (loc - 1 >= 0) {
        if (visit[loc - 1] == 0) {
            visit[loc - 1] = visit[loc] + 1;
            map.push_back(loc - 1);
        }
    }
    if (loc + 1 <= MAX_VALUE) {
        if (visit[loc + 1] == 0) {
            visit[loc + 1] = visit[loc] + 1;
            map.push_back(loc + 1);
        }
    }
    return;
}
int bfs(int start) {
    map.push_back(start);
    visit[start] = 0;
    int next = 0;
    while (!map.empty()) {
        next = map.front();
        map.pop_front();
        if (next == destination)
            return visit[next];
        checkMap(next);
    }
}

int main() {
    init();
    int start = 0;
    cin >> start >> destination;
    cout << bfs(start);
    return 0;
}