#include<iostream>
#include<vector>
using namespace std;

vector<int> wine_list;
int memory[10004][4];

int wineDp(int N) {
	memory[0][0] = 0;
	memory[0][1] = 0;
	memory[0][2] = 0;
	for (int i = 1; i < wine_list.size(); i++) {
		memory[i][0] = max(memory[i - 1][2], max(memory[i - 1][1], memory[i - 1][0]));
		memory[i][1] = memory[i - 1][0] + wine_list[i - 1];
		memory[i][2] = memory[i - 1][1] + wine_list[i - 1];
	}
	int result = max(memory[N - 1][0] + wine_list[N - 1], max(memory[N - 1][1] + wine_list[N - 1], memory[N - 1][2]));
	return result;
}

int main() {
	for (int i = 0; i < 10004; i++) {
		for (int j = 0; j < 4; j++)
			memory[i][j] = 0;
	}
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		wine_list.push_back(tmp);
	}
	cout << wineDp(N);
	return 0;
}