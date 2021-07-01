#include<iostream>
#include<string>
#include<vector>
using namespace std;



long long memory[100];
void setMemory();
long long binaryZero(int n);
long long binaryFriend(int n);
long long startBinary(int n);





int main() {
	setMemory();

	int testCase = 0;
	cin >> testCase;
	cout << startBinary(testCase);


	return 0;
}

void setMemory() {
	for (int i = 0; i < 100; i++)
		memory[i] = -1;
}

long long binaryZero(int n) {
	if (n == 0)
		return 1;
	return binaryFriend(n - 1);
}

long long binaryFriend(int n) {
	int ret = -1;
	if (n == 0)
		return 1;
	if (memory[n] != -1) {
		return memory[n];
	}
	memory[n] = binaryFriend(n - 1) + binaryZero(n - 1);
	return memory[n];

}

long long startBinary(int n) {
	return binaryZero(n - 1);
}

