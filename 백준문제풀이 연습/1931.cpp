#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 100000

using namespace std;
vector<pair<int, int>> conference;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    else {
        return a.second > b.second;
    }
}

int main() {
    init();
    int n = 0;
    cin >> n;
    pair<int, int> pairTemp;
    for (int i = 0; i < n; i++) {
        cin >> pairTemp.first >> pairTemp.second;
        conference.push_back(pairTemp);
    }
    sort(conference.begin(), conference.end(), compare);

    int temp = 0;
    int cnt = 1;
    temp = conference.back().second;
    conference.pop_back();
    while (!conference.empty()) {
        if (conference.back().first < temp) {
            ;
            conference.pop_back();
            continue;
        }
        else {
            cnt++;
            temp = conference.back().second;
            conference.pop_back();
        }
    }
    cout << cnt;
    return 0;
}