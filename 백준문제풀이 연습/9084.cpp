#include<iostream>
#include<vector>
using namespace std;

int memory[10004][22];
int coin[22];
int N;
int M;

int coin_dp(int nowCost,int nowCoinNum) {
	int tmp = nowCost;
	if (nowCoinNum == 1) {
		if ((M - nowCost) % coin[1] == 0)
			return 1;
		else
			return 0;
	}
	if (memory[nowCost][nowCoinNum] != -1) {
		return memory[nowCost][nowCoinNum];
	}
	if (nowCost == M)
		return 1;
	int result = 0;
	int nowCoin = coin[nowCoinNum];
	while (nowCost<=M) {
		result += coin_dp(nowCost, nowCoinNum - 1);
		nowCost += nowCoin;
	}
	memory[tmp][nowCoinNum] = result;
	return result;
}
void setMemory() {
	for (int i = 0; i < 10004; i++)
		for (int j = 0; j < 22; j++)
			memory[i][j] = -1;
	return;
}


int main() {
	int testCase = 0;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		setMemory();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> coin[i];
		}
		cin >> M;
		cout << coin_dp(0, N) << "\n";
	}
	return 0;
}