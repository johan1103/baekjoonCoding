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
    int n = 0;
    int temp = 0;
    vector<int> atm;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        atm.push_back(temp);
    }

    sort(atm.begin(), atm.end());
    int result = 0;
    for (int i = 0; i < atm.size(); i++) {
        result += n * atm[i];
        n -= 1;
    }
    cout << result;

    return 0;
}