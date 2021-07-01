#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 1000004

using namespace std;
int num = 0;
int remoteNum[10];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool checkNum(int number) {
    if (number == 0 && remoteNum[0] == 0) {
        return false;
    }
    while (number != 0) {
        if (remoteNum[number % 10] == 0)
            return false;
        else {
            number /= 10;
        }
    }
    return true;
}
void compare(int channel) {
    int plusMinus = 0;
    if (num >= 100)
        plusMinus = num - 100;
    else
        plusMinus = 100 - num;
    cout << min(channel, plusMinus);
    return;
}
int numSize(int num) {
    int cnt = 0;
    if (num == 0)
        return 1;
    while (num != 0) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int main() {
    init();
    memset(remoteNum, 1, sizeof(remoteNum));
    int n = 0;
    cin >> num >> n;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        remoteNum[temp] = 0;
    }
    if (n == 10) {
        compare(MAX_SIZE);
        return 0;
    }
    int topNum = num;
    int bottomNum = num;
    while (true) {
        if (checkNum(topNum))
            break;
        topNum++;
        if (topNum == MAX_SIZE)
            break;
    }
    while (true) {
        if (checkNum(bottomNum))
            break;
        bottomNum--;
        if (bottomNum == -1) {
            bottomNum = -MAX_SIZE;
            break;
        }
    }
    int topTime = topNum - num + numSize(topNum);
    int bottomTime = num - bottomNum + numSize(bottomNum);
    compare(min(topTime, bottomTime));
    return 0;
}