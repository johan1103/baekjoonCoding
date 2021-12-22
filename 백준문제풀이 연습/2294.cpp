#include<iostream>
#include<vector>
#define INF 100004
using namespace std;
vector<int> coin;
int dp[INF];
int N,K;

int coinDp() {
	for (int c = 0; c < coin.size(); c++) {
		dp[coin[c]] = 1;
		for (int i = coin[c]; i <= K; i++) {
			dp[i] = min(dp[i], dp[i - coin[c]] + 1);
//			cout << coin[c]<<" "<<i << " " << dp[i] << "\n";
		}
	}
	return dp[K];
}


int main() {
	for (int i = 0; i < INF; i++)
		dp[i] = INF;
	cin >> N >> K;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		coin.push_back(tmp);
	}
	int result = coinDp();
	if (result == INF)
		cout << -1;
	else
		cout << result;
	return 0;
}