#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 500004

using namespace std;

int numArr[10000003];
int minusNumArr[10000003];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}


int main() {
    init();
    int n = 0;
    cin >> n;
    int num = 0;
    memset(numArr, 0, sizeof(numArr));
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num >= 0)
            numArr[num] += 1;
        else
            minusNumArr[0 - num] += 1;
    }
    int t = 0, temp = 0;
    cin >> t;
    for (int j = 0; j < t; j++) {
        cin >> temp;
        if (temp >= 0)
            cout << numArr[temp] << " ";
        else
            cout << minusNumArr[0 - temp] << " ";
    }

    return 0;
}