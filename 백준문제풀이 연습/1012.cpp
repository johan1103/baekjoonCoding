#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

int map[55][55];
int visit[55][55];
int M, N, K;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int cabbage_bfs() {
	queue<pair<int, int>> cabbage;
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			if (map[j][i] == 1)
				cabbage.push({ j, i });
		}
	}
	int cnt = 0;
	while (!cabbage.empty()) {
		int x = cabbage.front().first;
		int y = cabbage.front().second;
		cabbage.pop();
		if (visit[x][y] != -1)
			continue;

		cnt += 1;
		queue<pair<int, int>> qu;
		qu.push({ x,y });
		while (!qu.empty()) {
			int nx = qu.front().first;
			int ny = qu.front().second;
			qu.pop();
			if (visit[nx][ny] != -1)
				continue;
			visit[nx][ny] = cnt;
			for (int i = 0; i < 4; i++) {
				int fx = nx + dx[i];
				int fy = ny + dy[i];
				if (fx >= M || fx < 0 || fy >= N || fy < 0)
					continue;
				if (map[fx][fy] == 1) {
					qu.push({ fx,fy });
				}
			}
		}
	}
	return cnt;
}

void setMemory() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			map[j][i] = 0;
			visit[j][i] = -1;
		}
	}
}

int main() {
	int testCase = 0;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		setMemory();
		cin >> M >> N >> K;
		for (int k = 0; k < K; k++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		cout << cabbage_bfs() << "\n";
	}
	return 0;
}