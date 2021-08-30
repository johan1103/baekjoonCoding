#include<iostream>
#include<vector>

using namespace std;

int memory[1004];
int arr[1004];
int arrSize = 0;

int longestSumArray(int nowNum) {
	int result = 0;
	if (memory[nowNum] != -1)
		return memory[nowNum];
	for (int i = nowNum + 1; i <= arrSize; i++) {
		if (arr[i] > arr[nowNum]) {
			result = max(result, longestSumArray(i));
		}
	}
	memory[nowNum] = result + arr[nowNum];
	return result + arr[nowNum];
}
void setMemory() {
	for (int i = 0; i <= arrSize; i++) {
		memory[i] = -1;
		arr[i] = 0;
	}
}


int main() {
	cin >> arrSize;
	setMemory();
	for (int i = 1; i <= arrSize; i++) {
		cin >> arr[i];
	}
	cout << longestSumArray(0);
	return 0;
}