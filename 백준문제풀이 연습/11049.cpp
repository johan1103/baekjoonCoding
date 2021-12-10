#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

long long int memory[504][504];
vector<pair<int, int>> matrix_list;

long long int minMatrixDp(int first_index,int second_index) {
	if (first_index == second_index)
		return 0;
	if (memory[first_index][second_index] != -1)
		return memory[first_index][second_index];
	long long int result = INF;
	for (int i = first_index; i < second_index; i++) {
		int multi_tmp = matrix_list[first_index].first * matrix_list[i].second;
		multi_tmp *= matrix_list[second_index].second;
		result = min(result, minMatrixDp(first_index, i) + minMatrixDp(i + 1, second_index) + multi_tmp);
	}
//	cout << first_index << " " << second_index << " " << result << "\n";
	memory[first_index][second_index] = result;
	return result;
}
void setMemory() {
	for (int i = 0; i < 504; i++)
		for (int j = 0; j < 504; j++)
			memory[j][i] = -1;
	return;
}

int main() {
	setMemory();
	int N = 0;
	cin >> N;
	pair<int, int> in_tmp;
	for (int i = 0; i < N; i++) {
		cin >> in_tmp.first;
		cin >> in_tmp.second;
		matrix_list.push_back(in_tmp);
	}
	cout << minMatrixDp(0, matrix_list.size() - 1);
	return 0;
}