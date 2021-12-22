#include<iostream>
#include<vector>
#define INF 1004
using namespace std;
int width, height;
int map[INF][INF];
int memory[INF][INF];

int candyDp(int nx,int ny) {
//	cout << nx << " " << ny << " " << map[nx][ny] << "\n";
	if (nx == 0 && ny == 0)return map[0][0];
	if (nx < 0 || nx >= width || ny < 0 || ny >= height)
		return 0;
	if (memory[nx][ny] != -1)
		return memory[nx][ny];
	int result = 0;
	result = max(candyDp(nx - 1, ny - 1), max(candyDp(nx - 1, ny), candyDp(nx, ny - 1)));
	result += map[nx][ny];
	memory[nx][ny] = result;
	return result;
}

void setMemory() {
	for (int i = 0; i < INF; i++)
		for (int j = 0; j < INF; j++)
			memory[j][i] = -1;
	return;
}

int main() {
	setMemory();
	cin >> height >> width;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			cin >> map[j][i];
	cout << candyDp(width - 1, height - 1);
	return 0;
}