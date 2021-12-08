#include<iostream>
#include<vector>
using namespace std;

int map[1004][1004];
int N;
int width, height;
int memory[1004][1004];
int max_square = 0;

int squareDp(int now_x,int now_y) {
	int result = 0;
	if (now_x >= width || now_y >= height)
		return 0;
	if (memory[now_x][now_y] != -1)
		return memory[now_x][now_y];
	if (map[now_x][now_y] == 0) {
		memory[now_x][now_y] = 0;
		return 0;
	}
	result = min(squareDp(now_x + 1, now_y + 1), min(squareDp(now_x + 1, now_y), squareDp(now_x, now_y + 1)));
	result += 1;
	memory[now_x][now_y] = result;
	max_square = max(max_square, result);
	return result;
}
void setMemory() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			memory[j][i] = -1;
			map[j][i] = 0;
		}
	return;
}

int main() {
	int N, M;
	cin >> N >> M;
	height = N;
	width = M;
	setMemory();
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			map[j][i] = int(tmp[j]) - 48;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			squareDp(j, i);
	}
	cout << max_square * max_square;
	return 0;
}