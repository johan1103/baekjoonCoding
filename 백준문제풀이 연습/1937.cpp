#include<iostream>
#include<vector>

using namespace std;

int map[509][509];
int memory[509][509];

int mapHeight;
int mapWidth;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int pandaRoot(int nx, int ny) {
	if (memory[nx][ny] != -1)
		return memory[nx][ny];
	int result = 1;
	for (int i = 0; i < 4; i++) {
		if (nx + dx[i] <= 0 || nx + dx[i] > mapWidth)
			continue;
		if (ny + dy[i] <= 0 || ny + dy[i] > mapHeight)
			continue;
		if (map[nx][ny] < map[nx + dx[i]][ny + dy[i]]) {
			result = max(result, 1 + pandaRoot(nx + dx[i], ny + dy[i]));
		}
	}
	memory[nx][ny] = result;
	return result;
}

void setMemory() {
	for (int i = 0; i <= mapHeight; i++) {
		for (int j = 0; j <= mapWidth; j++) {
			memory[j][i] = -1;
			map[j][i] = 0;
		}
	}
	return;
}


int main() {
	int result = 0;
	cin >> mapHeight;
	mapWidth = mapHeight;
	setMemory();
	for (int i = 1; i <= mapHeight; i++) {
		for (int j = 1; j <= mapWidth; j++) {
			cin >> map[j][i];
		}
	}
	for (int i = 1; i <= mapHeight; i++) {
		for (int j = 1; j <= mapWidth; j++) {
			result = max(result, pandaRoot(j, i));
		}
	}
	cout << result;
	return 0;
}