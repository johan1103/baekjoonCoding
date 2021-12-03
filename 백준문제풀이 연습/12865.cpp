#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//dp는 예외 없이 처음부터 쌓아나가는 것이 중요하다.
//중간에 최적화했던 값이 변하면 안된다.


vector<pair<int,int>> bag_list; //first 무게, second 가치
int memory[104][100004];

int ordinaryBagDp(int index,int left_weight) {
	int result = 0;
	if (index >= bag_list.size())
		return 0;
	if (memory[index][left_weight] != -1)
		return memory[index][left_weight];
	if (bag_list[index].first > left_weight) {
		result = ordinaryBagDp(index + 1, left_weight);
		memory[index][left_weight] = result;
		return result;
	}
	result = ordinaryBagDp(index + 1, left_weight - bag_list[index].first) + bag_list[index].second;
	result = max(result, ordinaryBagDp(index + 1, left_weight));
	memory[index][left_weight] = result;
	return result;
}
void setMemory() {
	for (int i = 0; i < 104; i++)
		for (int j = 0; j < 100004; j++)
			memory[i][j] = -1;
	return;
}

int main() {
	setMemory();
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V;
		bag_list.push_back({ W,V });
	}
	sort(bag_list.begin(), bag_list.end(), greater<pair<int, int>>());
//	for (int i = 0; i < bag_list.size(); i++)
//		cout << bag_list[i].first << " ";
	cout << ordinaryBagDp(0, K);
	return 0;
}