#include<iostream>
#include<string>
#include<vector>
using namespace std;

int dp[204][2];
int k = 0;

int numberSum(int n) {
	for (int i = 0; i < 204; i++)
		dp[i][0] = 1, dp[i][1] = 1;
	for (int kSize = 1; kSize <= k; kSize++) {
		for (int i = 1; i <= n; i++) {
			for (int iSize = 1; iSize <= i; iSize++) {
				dp[iSize][1] = dp[iSize][0] + dp[iSize - 1][1];
			}
		}
		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i][1];
			dp[i][1] = 0;
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += dp[i][0];
	}
	return result;
}


int main() {
	cin >> k;
	cout << numberSum(3);

	return 0;
}
