#include<iostream>
#include<vector>
#define INF 204
using namespace std;

int memory[INF][INF];

int sumDp(int n,int k) {
	if (k == 1)
		return 1;
	if (memory[n][k] != -1)
		return memory[n][k];
	int result = 0;
	for (int i = 0; i <= n; i++) {
		result = (result + sumDp(n - i, k - 1)) % 1000000000;
	}
	memory[n][k] = result;
	return result;
}

int main() {
	for (int i = 0; i < INF; i++)
		for (int j = 0; j < INF; j++)
			memory[j][i] = -1;
	int N, K;
	cin >> N >> K;
	cout << sumDp(N, K);
	return 0;
}