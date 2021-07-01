#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 2190

using namespace std;
int cnt = 0;
vector<pair<int, int>> route;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void hanoi(int block, int nowLoc, int endLoc) {
    pair<int, int> temp;
    temp.first = nowLoc;
    temp.second = endLoc;
    if (block == 1) {
        route.push_back(temp);
        cnt += 1;
        return;
    }
    int elseLoc = 6 - (nowLoc + endLoc);
    hanoi(block - 1, nowLoc, elseLoc);
    route.push_back(temp);
    cnt += 1;
    hanoi(block - 1, elseLoc, endLoc);
}

int main() {
    init();
    int n = 0;
    cin >> n;
    hanoi(n, 1, 3);
    cout << cnt << "\n";

    for (int i = 0; i < route.size(); i++) {
        cout << route[i].first << " " << route[i].second << "\n";
    }

    return 0;
}