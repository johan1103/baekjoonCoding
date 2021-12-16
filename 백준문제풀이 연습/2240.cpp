#include<iostream>
#include<vector>
#define INF 1004
using namespace std;

vector<int> plum_arr;
int memory[INF][33][2];

int plumDp(int index,int change,int location) {
	int result = 0;
	if (index >= plum_arr.size())
		return 0;
	if (memory[index][change][location] != -1)
		return memory[index][change][location];
	int a_side = 0;
	int b_side = 0;
	if (plum_arr[index] == location + 1)
		a_side = 1;
	else
		b_side = 1;
	if (change <= 0)
		result = a_side + plumDp(index + 1, change, location);
	else
		result = max(plumDp(index + 1, change - 1, (location + 1) % 2) + b_side,
			plumDp(index + 1, change, location) + a_side);
	memory[index][change][location] = result;
	return result;
}
void setMemory() {
	for (int i = 0; i < INF; i++) {
		for (int j = 0; j < 33; j++) {
			memory[i][j][0] = -1;
			memory[i][j][1] = -1;
		}
	}
}


int main() {
	setMemory();
	int N;
	int C;
	cin >> N >> C;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		plum_arr.push_back(tmp);
	}
		cout << plumDp(0, C, 0);
	return 0;
}