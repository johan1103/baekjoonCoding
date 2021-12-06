#include<iostream>
#include<vector>
#define INF 10e9
using namespace std;

vector<int> file_list;
vector<int> file_sum_list;
int memory[504][504];

int fileDp(int start_index,int end_index) {
	if (memory[start_index][end_index] != -1)
		return memory[start_index][end_index];
	if (start_index == end_index)
		return 0;
	if (start_index + 1 == end_index)
		return file_list[start_index] + file_list[end_index];
	int result = INF;
	for (int i = start_index; i < end_index; i++) {
		int tmp = fileDp(start_index, i) + fileDp(i + 1, end_index);
		tmp += file_sum_list[i] - file_sum_list[start_index - 1];
		tmp += file_sum_list[end_index] - file_sum_list[i];
		result = min(result, tmp);
	}
	memory[start_index][end_index] = result;
//	cout << start_index << " " << end_index << " || " << result << "\n";
	return result;
}
void setMemory() {
	for (int i = 0; i < 504; i++) {
		for (int j = 0; j < 504; j++)
			memory[j][i] = -1;
	}
	while (!file_list.empty())
		file_list.pop_back();
	while (!file_sum_list.empty())
		file_sum_list.pop_back();
	return;
}

int main() {
	int T, K;
	cin >> T;
	for (int t = 0; t < T; t++) {
		setMemory();
		file_list.push_back(0);
		file_sum_list.push_back(0);
		cin >> K;
		int tmp;
		int sum_tmp = 0;
		for (int i = 0; i < K; i++) {
			cin >> tmp;
			sum_tmp += tmp;
			file_sum_list.push_back(sum_tmp);
			file_list.push_back(tmp);
		}
		cout << fileDp(1, K) << "\n";
	}
	return 0;
}