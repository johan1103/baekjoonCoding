#include<iostream>
#include<string>
#include<vector>
using namespace std;


void triangle(int n) {
	long long memory[104] = { 0, };
	for (int i = 1; i < 4; i++)
		memory[i] = 1;
	memory[4] = 2, memory[5] = 2;
	for (int i = 6; i <= n; i++)
		memory[i] = memory[i - 1] + memory[i - 5];
	cout << memory[n];
}

int main() {
	int testCase = 0;
	int num = 0;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> num;
		triangle(num);
		cout << "\n";
	}
	return 0;
}
