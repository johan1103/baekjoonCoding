#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 300000

using namespace std;

int visitNum[MAX_SIZE];
int map[MAX_SIZE];
int n = 0;
void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int cal(int num) {
    int result = 0;
    int halfRe = 1;
    int temp = 0;
    while (num != 0) {
        temp = num % 10;
        for (int i = 0; i < n; i++)
            halfRe *= temp;
        result += halfRe;
        halfRe = 1;
        num /= 10;
    }
    return result;
}

void dfs(int start) {
    visitNum[start] = 1;
    int next = cal(start);
    map[start] = next;
    if (visitNum[next] == 1) {
        visitNum[next] += 1;
        return;
    }
    else {
        dfs(next);
    }
}

int arrSize(int start) {
    int next = map[start];
    if (visitNum[next] == 2)
        return 1;
    else {
        return arrSize(next) + 1;
    }
}

int main() {
    init();
    int num = 0;
    cin >> num >> n;
    dfs(num);
    if (visitNum[num] == 2)
        cout << "0";
    else
        cout << arrSize(num);
    return 0;
}
