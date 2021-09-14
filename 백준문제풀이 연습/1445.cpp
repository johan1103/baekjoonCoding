#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

int map[55][55];
int dist[55][55];
int garbage_map[55][55];
int N, M;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int date_dijkstra(int startLoc_x,int startLoc_y,int finalLoc_x,int finalLoc_y) {
	priority_queue<pair<int, pair<int, int>>> qu;
	dist[startLoc_x][startLoc_y] = map[startLoc_x][startLoc_y];
	qu.push(make_pair(-dist[startLoc_x][startLoc_y], make_pair(startLoc_x, startLoc_y)));
	while (!qu.empty()) {
		int nx = qu.top().second.first;
		int ny = qu.top().second.second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = nx + dx[i];
			int next_y = ny + dy[i];
			if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
				continue;
			if (dist[nx][ny] + map[next_x][next_y] < dist[next_x][next_y]) {
				dist[next_x][next_y] = dist[nx][ny] + map[next_x][next_y];
				qu.push(make_pair(-dist[next_x][next_y], make_pair(next_x, next_y)));
			}
		}
	}
	return dist[finalLoc_x][finalLoc_y];
}

void setMemory() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			map[j][i] = 0;
			garbage_map[j][i] = 0;
			dist[j][i] = INF;
		}
	}
}
void setGarbageMap() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[x][y] == 2600) {
				for (int i = 0; i < 4; i++) {
					int next_x = x + dx[i];
					int next_y = y + dy[i];
					if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
						continue;
					else if (map[next_x][next_y] == 0)
						map[next_x][next_y] = 1;
				}
			}
		}
	}
}


int main() {
	setMemory();
	string tmp;
	int startLoc_x = 0;
	int startLoc_y = 0;
	int finalLoc_x = 0;
	int finalLoc_y = 0;
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> tmp;
		for (int x = 0; x < M; x++) {
			map[x][y] = tmp[x];
			if (tmp[x] == '.')
				map[x][y] = 0;
			else if (tmp[x] == 'g') {
				map[x][y] = 2600;
			}
			else if (tmp[x] == 'S') {
				map[x][y] = 0;
				startLoc_x = x;
				startLoc_y = y;
			}
			else if (tmp[x] == 'F') {
				map[x][y] = 0;
				finalLoc_x = x;
				finalLoc_y = y;
			}
		}
	}
	setGarbageMap();
	map[startLoc_x][startLoc_y] = 0;
	map[finalLoc_x][finalLoc_y] = 0;
	int result = date_dijkstra(startLoc_x, startLoc_y, finalLoc_x, finalLoc_y);
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dist[j][i] << " ";
		}
		cout << "\n";
	}
	*/
	cout << int(result / 2600) << " " << result % 2600;
	return 0;
}