#include<iostream>
#include<vector>
#define INF 1004
using namespace std;

int N, M;
int map[INF][INF];
int dp[INF][INF][2];

int nasaDP() {
	int result = 0;
	dp[0][0][0] = map[0][0];
	dp[0][0][1] = map[0][0];
	for (int i = 1; i < M; i++) {
		dp[i][0][0] = dp[i - 1][0][0] + map[i][0];
		dp[i][0][1] = dp[i - 1][0][1] + map[i][0];
	}
	for (int i = 1; i < N; i++) {
		dp[0][i][0] = map[0][i] + max(dp[0][i - 1][0], dp[0][i - 1][1]);
		dp[M - 1][i][1] = map[M - 1][i] + max(dp[M - 1][i - 1][0], dp[M - 1][i - 1][1]);
		for (int j = 1; j < M; j++) {
			dp[j][i][0] = max(dp[j - 1][i][0], max(dp[j][i - 1][0], dp[j][i - 1][1]));
			dp[j][i][0] += map[j][i];
		}
		for (int j = M - 2; j >= 0; j--) {
			dp[j][i][1] = max(dp[j + 1][i][1], max(dp[j][i - 1][0], dp[j][i - 1][1]));
			dp[j][i][1] += map[j][i];
		}
	}
	result = max(dp[M - 1][N - 1][0], dp[M - 1][N - 1][1]);
	return result;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[j][i];
	}
	cout << nasaDP();
	/*
	cout << "\n\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << dp[j][i][0] << " ";
		cout << "\n";
	}
	cout << "\n\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << dp[j][i][1] << " ";
		cout << "\n";
	}
	cout << "\n\n\n";
	*/
	return 0;
}