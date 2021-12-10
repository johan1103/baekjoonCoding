#include<iostream>
using namespace std;

int memory[1000][100];
int N, M;

int bridgeDp(int left_index,int right_index) {
	int sum = 0;
	if (left_index >= N)
		return 1;
	if (right_index >= M)
		return 0;
	if (memory[left_index][right_index] != -1)
		return memory[left_index][right_index];
	for (int i = right_index; i < M; i++) {
		sum += bridgeDp(left_index + 1, i + 1);
	}
	memory[left_index][right_index] = sum;
	return sum;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 100; j++)
				memory[i][j] = -1;
		}
		cin >> N >> M;
		cout << bridgeDp(0, 0) << "\n";
	}
	return 0;
}