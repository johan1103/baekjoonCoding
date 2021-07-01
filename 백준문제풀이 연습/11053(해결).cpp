#include<iostream>
#include<string>
#include<vector>
using namespace std;

int memory[1004];
int arrSize = 0;
int arr[1004];
void setMemory() {
	for (int i = 0; i < 1004; i++)
		memory[i] = -1;
}

void longestArr(int nowNum) {
	int maxArr = 1;
	for (int i = 1; i < nowNum; i++) {
		if (arr[nowNum] <= arr[i])
			continue;
		maxArr = max(maxArr, 1 + memory[i]);
	}
	memory[nowNum] = maxArr;
	return;
}

void resultArr(int size) {
	for (int i = 1; i <= size; i++)
		longestArr(i);
}


int main() {
	setMemory();
	cin >> arrSize;
	for (int i = 1; i <= arrSize; i++)
		cin >> arr[i];
	resultArr(arrSize);
	int maxNum = 0;
	for (int i = 1; i <= arrSize; i++)
		maxNum = max(maxNum, memory[i]);
	cout << maxNum;

	return 0;
}
