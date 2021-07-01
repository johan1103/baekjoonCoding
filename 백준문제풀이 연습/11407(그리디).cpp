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
int coinNum(int price, int nowCoin) {
    int temp = 0;
    temp = price / coin[nowCoin];
    if (price % coin[nowCoin] == 0)
        return temp;
    else
        return coinNum(price % coin[nowCoin], nowCoin - 1) + temp;
}

int main() {
    init();
    int t = 0;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    cout << coinNum(t, n - 1);
    return 0;
}