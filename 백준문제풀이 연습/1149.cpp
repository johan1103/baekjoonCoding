#include<iostream>
#include<vector>
#define INF 1004
using namespace std;

int dp[INF][3];
int map[INF][3];
int N;

int paintingDp() {
	dp[0][0] = map[0][0]; dp[0][1] = map[0][1]; dp[0][2] = map[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][0] += map[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][1] += map[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		dp[i][2] += map[i][2];
	}
	return min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i][0] >> map[i][1] >> map[i][2];
	}
	cout << paintingDp();
	return 0;
}

