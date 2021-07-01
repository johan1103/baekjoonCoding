#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 100000

using namespace std;
int coin[10];
int n = 0;
int maxPrice = 0;
int memory[MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
int coinNum(int price) {
    //    cout << price << "\n";
    if (memory[price] != 0)
        return memory[price];
    int result = MAX_SIZE - 30;
    for (int i = n - 1; i >= 0; i--) {
        if (price - coin[i] < 0)
            continue;
        else if (price - coin[i] == 0)
            return 1;
        result = min(result, coinNum(price - coin[i]) + 1);
    }
    memory[price] = result;
    return result;
}

int main() {
    init();
    int k = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    cout << coinNum(k);
    return 0;
}