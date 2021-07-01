#include<iostream>
#include<string>
#include<vector>
using namespace std;

int memory[12];
void setMemory() {
	for (int i = 0; i < 12; i++)
		memory[i] = -1;
}
int number(int leftNum) {
	if (leftNum == 0)
		return 1;
	if (leftNum < 0)
		return 0;
	if (memory[leftNum] != -1)
		return memory[leftNum];

	return number(leftNum - 1) + number(leftNum - 2) + number(leftNum - 3);

}



int main() {
	setMemory();
	int testCase = 0;
	int num = 0;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> num;
		cout << number(num) << "\n";
	}
	return 0;
}
