#include<iostream>
#include<string>
#include<vector>
using namespace std;

int memory[100004];

void times(int nowNum) {
	for (int i = 1; i * i <= nowNum; i++)
		if (i * i == nowNum) {
			memory[nowNum] = 1;
			return;
		}
	int result = 100004;
	for (int i = 1; i <= nowNum / 2; i++) {
		result = min(result, (memory[i] + memory[nowNum - i]));
	}
	memory[nowNum] = result;
	return;
}

int resultTimes(int num) {
	for (int i = 1; i <= num; i++)
		times(i);
	return memory[num];
}

int main() {
	int num = 0;
	cin >> num;
	cout << resultTimes(num);
	return 0;
}
