#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 500004

using namespace std;

int numArr[10000003];
int n = 0;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool possible(int num) {
    int low = 0, high = n - 1;
    while (high >= low) {
        int mid = (low + high) / 2;
        if (num > numArr[mid]) {
            low = mid + 1;
        }
        else if (num <= numArr[mid]) {
            high = mid - 1;
        }
        if (numArr[mid] == num) {
            return true;
        }
    }
    return 0;
}

int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numArr[i];
    }
    sort(numArr, numArr + n);
    int t = 0;
    cin >> t;
    int num = 0;
    for (int i = 0; i < t; i++) {
        cin >> num;
        if (possible(num)) {
            cout << "1 ";
        }
        else
            cout << "0 ";
    }
    /*
    while (high >= low) {
        int mid = (low + high) / 2;
        if (num > mid) {
            low = mid + 1;
        }
        else if (num <= mid) {
            high = mid - 1;
        }
    }
    */
    return 0;
}