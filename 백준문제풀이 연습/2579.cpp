#include<iostream>
#include<string>
#include<vector>
using namespace std;

int arrSize = 0;
int arr[304];
int memory[304];

void stairMax(int nowNum) {
	int result = 0;
	result = max(memory[nowNum - 2] + arr[nowNum], arr[nowNum] + arr[nowNum - 1] + memory[nowNum - 3]);
	memory[nowNum] = result;
	return;
}
int stairResult() {
	memory[0] = 0;
	memory[1] = arr[1];
	memory[2] = arr[2] + arr[1];
	for (int i = 3; i <= arrSize; i++) {
		stairMax(i);
	}
	return memory[arrSize];
}


int main() {
	for (int i = 0; i < 304; i++)
		arr[i] = 0;
	cin >> arrSize;
	for (int i = 1; i <= arrSize; i++)
		cin >> arr[i];

	cout << stairResult();

	return 0;
}
