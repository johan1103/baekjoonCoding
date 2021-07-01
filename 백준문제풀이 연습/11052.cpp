#include<iostream>
#include<string>
#include<vector>
using namespace std;

int cardPay[1004];
int memory[1004];

int cardMaxCost(int leftCard) {
	if (leftCard == 0)
		return 0;
	if (memory[leftCard] != -1)
		return memory[leftCard];
	int result = 0;
	for (int i = 1; i <= leftCard; i++) {
		result = max(result, cardMaxCost(leftCard - i) + cardPay[i]);
	}
	memory[leftCard] = result;
	return result;
}

int main() {
	for (int i = 0; i < 1004; i++)
		memory[i] = -1;
	int cardSize = 0;
	cin >> cardSize;
	for (int i = 1; i <= cardSize; i++) {
		cin >> cardPay[i];
	}
	cout << cardMaxCost(cardSize);


	return 0;
}
