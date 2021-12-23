#include<iostream>
#include<algorithm>
#include<vector>
#define INF 100000
using namespace std;

vector<pair<int, int>> line;
int N;
int dp[INF];

int lineDp() {
	int result = 0;
	sort(line.begin(), line.end());
	for (int i = 0; i < line.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (line[i].second > line[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		result = max(result, dp[i]);
	}
	return line.size() - result;
}

int main() {
	int a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		line.push_back({ a,b });
	}
	cout << lineDp();
	return 0;
}