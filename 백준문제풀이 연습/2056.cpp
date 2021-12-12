#include<iostream>
#include<vector>
#define INF 10004
using namespace std;

vector<int> map[INF];
int cost_time[INF];
int memory[INF];

int workingDp(int now_node) {
	if (memory[now_node] != -1)
		return memory[now_node];
	int result = 0;
	for (int i = 0; i < map[now_node].size(); i++) {
		int next_node = map[now_node][i];
		result = max(result, workingDp(next_node));
	}
	result += cost_time[now_node];
//	cout << now_node << " " << result << "\n";
	memory[now_node] = result;
	return result;
}
void setMemory(int N) {
	for (int i = 0; i <= N; i++) {
		cost_time[i] = 0;
		memory[i] = -1;
	}
	return;
}

int main() {
	int N;
	cin >> N;
	setMemory(N);
	for (int i = 1; i <= N; i++) {
		cin >> cost_time[i];
		int tmp = 0;
		int nxt_tmp = 0;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			cin >> nxt_tmp;
			map[i].push_back(nxt_tmp);
		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		result = max(result, workingDp(i));
	}
	cout << result;
	return 0;
}