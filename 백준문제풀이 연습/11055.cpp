#include<iostream>
#include<string>
#include<vector>
using namespace std;

int memory[1004];
int arrSize = 0;
int arr[1004];

void maxSumArr(int nowNum) {
	int result = arr[nowNum];
	for (int i = 1; i < nowNum; i++) {
		if (arr[nowNum] <= arr[i])
			continue;
		result = max(result, arr[nowNum] + memory[i]);
	}
	memory[nowNum] = result;
	return;
}

int resultSum(int arrSize) {
	int result = 0;
	for (int i = 1; i <= arrSize; i++)
		maxSumArr(i);
	for (int i = 1; i <= arrSize; i++)
		result = max(result, memory[i]);
	return result;
}

int main() {
	cin >> arrSize;
	for (int i = 1; i <= arrSize; i++)
		cin >> arr[i];
	cout << resultSum(arrSize);

	return 0;
}
