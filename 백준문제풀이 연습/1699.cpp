#include<iostream>
#include<string>
#include<vector>
#define INF 100004
using namespace std;

int dp[INF];

int timesDp(int K) {
	dp[0] = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i - j * j] + 1, dp[i]);
		}
	}
	return dp[K];
}

int main() {
	for (int i = 0; i < INF; i++)
		dp[i] = INF;
	int N;
	cin >> N;
//	int start_time = clock();
	cout << timesDp(N);
//	int end_time = clock();
//	cout << "cost " << end_time - start_time;
	return 0;
}
