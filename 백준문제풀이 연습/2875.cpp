#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 100000

using namespace std;
void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    init();
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    int team = 0;
    int leftPeople = 0;
    if (n >= m * 2) {
        team = m;
        leftPeople = n - m * 2;
    }
    else {
        team = n / 2;
        leftPeople = m - n / 2;
    }
    if (k <= leftPeople)
        cout << team;
    else {
        k -= leftPeople;
        if (k % 3 == 0)
            team -= k / 3;
        else
            team -= (k / 3) + 1;
        cout << team;
    }
    return 0;
}