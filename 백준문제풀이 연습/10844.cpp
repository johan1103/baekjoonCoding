#include<iostream>
#include<string>
#include<vector>
using namespace std;

int memory[104][11];
void setMemory() {
	for (int i = 0; i < 11; i++) {
		for (int t = 0; t < 104; t++) {
			memory[t][i] = -1;
		}
	}
}
int stairNum(int chiper, int nowNum) {
	if (nowNum >= 10 || nowNum <= -1)
		return 0;
	if (chiper == 1)
		return 1;
	if (memory[chiper][nowNum] != -1)
		return memory[chiper][nowNum];

	int ret = 0;
	ret = (stairNum(chiper - 1, nowNum - 1) + stairNum(chiper - 1, nowNum + 1)) % 1000000000;
	memory[chiper][nowNum] = ret;
	return ret;
}

int AllStairNum(int chiper) {
	int result = 0;
	for (int i = 1; i < 10; i++) {
		result += stairNum(chiper, i);
		//		cout << result << "\n";
		result = result % 1000000000;
		//	cout << "fix result : " << result << "\n";
	}
	return result;
}




int main() {
	setMemory();
	int testCase = 0;
	cin >> testCase;
	cout << AllStairNum(testCase);

	return 0;
}
