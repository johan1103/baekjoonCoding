#include<iostream>
#include<vector>
using namespace std;

int row, col;

int map[1004][1004];
int memory[1004][1004];

const int d_col1[3] = { 1,1,0 };
const int d_row1[3] = { -1,0,1 };

const int d_row2[3] = { 1,1,0 };
const int d_col2[3] = { 0,1,1 };

int honey_dp(int now_row,int now_col) {
	if (now_row == row && now_col == col)
		return 1;
	if (map[now_row][now_col] == 1)
		return 0;
	if (memory[now_row][now_col] != -1)
		return memory[now_row][now_col];
	int result = 0;
	if (now_col % 2 == 1) {
		for (int i = 0; i < 3; i++) {
			int next_row = now_row + d_row1[i];
			int next_col = now_col + d_col1[i];
			if (next_row > row || next_col > col || next_row <= 0 || now_col <= 0)
				continue;
			result += honey_dp(next_row, next_col);
			result %= 1000000000 + 7;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			int next_row = now_row + d_row2[i];
			int next_col = now_col + d_col2[i];
			if (next_row > row || next_col > col || next_row <= 0 || now_col <= 0)
				continue;
			result += honey_dp(next_row, next_col);
			result %= 1000000000 + 7;
		}
	}
	memory[now_row][now_col] = result;
	return result;
}

void setMemory() {
	for (int i = 0; i < 1004; i++) {
		for (int j = 0; j < 1004; j++) {
			map[j][i] = 0;
			memory[j][i] = -1;
		}
	}
}

int main() {
	setMemory();
	int k = 0;
	cin >> row >> col;
	cin >> k;
	int empty_row, empty_col;
	for (int i = 0; i < k; i++) {
		cin >> empty_row >> empty_col;
		map[empty_row][empty_col] = 1;
	}
	cout << honey_dp(1, 1);
	return 0;
}