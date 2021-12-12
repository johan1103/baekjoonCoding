#include<iostream>
#include<vector>
#define INF 100000
using namespace std;

int dp[INF][2];
vector<int> num_list;

int listDp() {
	if (num_list.size() == 1)
		return num_list[0];
	dp[0][0] = num_list[0];
	dp[0][1] = num_list[0];
	dp[1][0] = max(num_list[0] + num_list[1], num_list[1]);
	dp[1][1] = dp[1][0];
	for (int i = 2; i < num_list.size(); i++) {
		dp[i][0] = max(dp[i - 1][0] + num_list[i], num_list[i]);
		dp[i][1] = max(dp[i - 1][1] + num_list[i], dp[i - 2][0] + num_list[i]);
	}
	int result = num_list[0];
	for (int i = 0; i < num_list.size(); i++) {
		result = max(dp[i][0], max(result, dp[i][1]));
	}
	return result;
}

int main() {
	int N;
	int tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num_list.push_back(tmp);
	}
	cout << listDp();
	return 0;
}