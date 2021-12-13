#include<iostream>
#include<vector>
#define INF 504
using namespace std;
int N;
int map[INF][INF];
int dp[INF][INF];

int triangleDp() {
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == i) {
				dp[j][i] = dp[j - 1][i - 1] + map[j][i];
				continue;
			}
			else if (j == 1) {
				dp[1][i] = dp[1][i - 1] + map[1][i];
				continue;
			}
			dp[j][i] = max(dp[j - 1][i - 1], dp[j][i - 1]);
			dp[j][i] += map[j][i];
		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		result = max(result, dp[i][N]);
	}
	return result;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> map[j][i];
		}
	}
	cout << triangleDp();
	return 0;
}