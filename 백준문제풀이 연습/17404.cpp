#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int visit[1004][3];
int color_cost[1004][3];
int first_num;
int N;

int RGB_dp(int start,int nowNum) {
	if (start == N) {
		if (nowNum == first_num)
			return INF / 10;
		return color_cost[N][nowNum];
	}
	if (visit[start][nowNum] != -1)
		return visit[start][nowNum];
	int result = INF;
	for (int i = 0; i < 3; i++) {
		if (i == nowNum)
			continue;
		else {
			result = min(result, color_cost[start][nowNum] + RGB_dp(start + 1, i));
		}
	}
	visit[start][nowNum] = result;
	return result;
}

void setMemory() {
	for (int i = 0; i < 1004; i++) {
		visit[i][0] = -1;
		visit[i][1] = -1;
		visit[i][2] = -1;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color_cost[i][j];
		}
	}
	int result = INF;
	for (int i = 0; i < 3; i++) {
		first_num = i;
		setMemory();
		result = min(result, RGB_dp(1, i));
	}
	cout << result;
	return 0;
}