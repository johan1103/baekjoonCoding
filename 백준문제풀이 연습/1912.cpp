#include<iostream>
#include<string>
#include<vector>
using namespace std;

int memory[100004];
int arr[100004];

void partSum(int nowNum) {
	if (nowNum == 1) {
		memory[nowNum] = arr[1];
		return;
	}
	int result = arr[nowNum];
	result = max(result, memory[nowNum - 1] + result);
	memory[nowNum] = result;
	return;
}

int ansPartSum(int arrSize) {
	int result = -2147483647;
	for (int i = 1; i <= arrSize; i++) {
		partSum(i);
		result = max(result, memory[i]);
	}
	return result;
}


int main() {
	int arrSize = 0;
	cin >> arrSize;
	for (int i = 1; i <= arrSize; i++)
		cin >> arr[i];
	cout << ansPartSum(arrSize);
	return 0;
}
