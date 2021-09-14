#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int map[55][55];
int dist[55][55];
int N;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int makingMaze_dijkstra();
void setMemory();


int main() {
	setMemory();
	string tmp;
	cin >> N;
	for (int y = 0; y < N; y++) {
		cin >> tmp;
		for (int x = 0; x < N; x++) {
			map[x][y] = 49 - int(tmp[x]);
		}
	}
	cout << makingMaze_dijkstra();
	return 0;
}


int makingMaze_dijkstra() {
	priority_queue < pair<int, pair<int, int>>> qu;
	dist[0][0] = 0;
	qu.push(make_pair(-dist[0][0], make_pair(0, 0)));
	while (!qu.empty()) {
		int nx = qu.top().second.first;
		int ny = qu.top().second.second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = nx + dx[i];
			int next_y = ny + dy[i];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			if (dist[nx][ny] + map[next_x][next_y] < dist[next_x][next_y]) {
				dist[next_x][next_y] = dist[nx][ny] + map[next_x][next_y];
				qu.push(make_pair(-dist[next_x][next_y], make_pair(next_x, next_y)));
			}
		}
	}
	return dist[N - 1][N - 1];
}
void setMemory() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			map[j][i] = 0;
			dist[j][i] = INF;
		}
	}
}