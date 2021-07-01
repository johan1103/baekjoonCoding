#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 100000

using namespace std;
int arr[MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    init();
    int E = 0, S = 0, M = 0;
    int temp1, temp2, temp3;
    cin >> E >> S >> M;
    for (int i = 0; i < MAX_SIZE; i++) {
        temp1 = 15 * i + E;
        temp2 = 28 * i + S;
        temp3 = 19 * i + M;
        arr[temp1] += 1;
        arr[temp2] += 1;
        arr[temp3] += 1;
        if (arr[temp1] >= 3) {
            cout << temp1;
            break;
        }
        else if (arr[temp2] >= 3) {
            cout << temp2;
            break;
        }
        else if (arr[temp3] >= 3) {
            cout << temp3;
            break;
        }
    }
    return 0;
}