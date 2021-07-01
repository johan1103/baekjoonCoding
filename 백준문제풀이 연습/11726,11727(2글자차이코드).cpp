#include<iostream>
#include<string>
#include<vector>
using namespace std;

long long memory[1004];
void setMemory();
long long block(int line);
long long widthBlock(int line);

int main() {
	setMemory();
	int testCase = 0;
	cin >> testCase;

	cout << block(testCase);
	return 0;
}


void setMemory() {
	for (int i = 0; i < 1004; i++)
		memory[i] = -1;
}

long long block(int line) {
	if (line == 0)
		return 1;
	if (memory[line] != -1)
		return memory[line];
	long long ret = -1;
	ret = (block(line - 1) + widthBlock(line - 1) * 2) % 10007; //여기에 widthBlock함수에 2곱하냐 안 곱하냐의 차이
	memory[line] = ret;
	return ret;

}

long long widthBlock(int line) {
	if (line == 0)
		return 0;
	return block(line - 1);
}

