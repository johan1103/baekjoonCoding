#include<iostream>
#include<string>
#include<vector>
using namespace std;

int memory[5004];
int code[5004];
int codeSize = 0;


int secretCode(int nowCode) {
	if (nowCode > codeSize)
		return 0;
	if (nowCode == codeSize)
		return 1;
	if (code[nowCode] == 0) {
		return 0;
	}
	if (memory[nowCode] != -1)
		return memory[nowCode];
	int sum = 0;
	if (code[nowCode] == 1 || (code[nowCode] == 2 && code[nowCode + 1] >= 0 && code[nowCode + 1] <= 6))
		sum += secretCode(nowCode + 2);
	sum += secretCode(nowCode + 1);
	sum %= 1000000;
	memory[nowCode] = sum;
	return sum;
}


int main() {
	for (int i = 0; i < 5004; i++) {
		memory[i] = -1;
		code[i] = -1;
	}
	string number;
	cin >> number;
	for (int i = 0; i < number.size(); i++) {
		code[i] = number[i] - '0';
	}
	codeSize = number.size();
	cout << secretCode(0);

	return 0;
}
