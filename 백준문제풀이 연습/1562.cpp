#include<iostream>
#include<vector>
#define INF 104
#define DIV 1000000000
using namespace std;

int length;
int memory[104][11][(1 << 10) + 10];
int total_sum = 0;

int startDp(int index,int num,int state) {
//	cout << index << " " << state << "\n";
//	cout << "lenght " << index << " ";
	if (num < 0 || num>9)
		return 0;
	state = (state | (1 << num));
	if (index == length - 1) {
		if (state == total_sum) {
//			cout << "°è»ê\n";
//			cout << index << " " << state << "\n";
			return 1;
		}
		else {
			return 0;
		}
	}
	if (memory[index][num][state] != -1) {
//		cout << "index " << index << " num " << num << " state " << state << "\n";
		return memory[index][num][state];
	}
	int result = 0;
	result = (startDp(index + 1, num + 1, state) + startDp(index + 1, num - 1, state)) % DIV;
	memory[index][num][state] = result;
//	cout << index << " " << state << "\n";
	return result;
}
void setMemory() {
	for (int i = 0; i < 104; i++) {
		for (int t = 0; t < 11; t++)
			for (int j = 0; j < (1 << 10)+10; j++)
				memory[i][t][j] = -1;
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		total_sum = (total_sum << 1) + 1;
	cin >> length;
	int result = 0;
	for (int i = 1; i < 10; i++) {
		setMemory();
		result = (result + startDp(0, i, 0)) % DIV;
	}
	cout << result;
	return 0;
}