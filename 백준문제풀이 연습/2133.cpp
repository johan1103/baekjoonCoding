#include<iostream>
#include<vector>
#define INF 33
using namespace std;
int dp[INF][2];

int blockDp(int n) {
	dp[0][0] = 1;
	dp[0][1] = 0;
	for (int i = 0; i <= n; i+=2) {
		dp[i + 2][0] += dp[i][0] * 3;
		dp[i + 2][1] += dp[i][0] * 2;
		dp[i + 2][0] += dp[i][1];
		dp[i + 2][1] += dp[i][1];
	}
	return dp[n][0];
}

int main() {
	int N;
	cin >> N;
	cout << blockDp(N);
	return 0;
}