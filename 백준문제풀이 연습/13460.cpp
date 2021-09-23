#include<iostream>
#include<string>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

// ºó°ø°£ 0 º® 1 »¡°£°ø 2 ÆÄ¶õ°ø 3 µµÂøÁ¡ 5
int map[13][13];
int visit[105][105];
int width, height;
int final_loc_x, final_loc_y;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int ball_bfs(int red_x, int red_y, int blue_x, int blue_y);
pair<int, int> ball_move(int red_x, int red_y, int blue_x, int blue_y, int move);

void setMemory() {
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			visit[j][i] = -1;
		}
	}
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++)
			map[j][i] = 0;
	}
}

int main() {
	setMemory();
	string sen;
	int red_x = 0, red_y = 0, blue_x = 0, blue_y = 0;
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		cin >> sen;
		for (int j = 0; j < sen.size(); j++) {
			if (sen[j] == '#')
				map[j][i] = 1;
			else if (sen[j] == '.')
				map[j][i] = 0;
			else if (sen[j] == 'B') {
				blue_x = j;
				blue_y = i;
				map[j][i] = 0;
			}
			else if (sen[j] == 'R') {
				red_x = j;
				red_y = i;
				map[j][i] = 0;
			}
			else if (sen[j] == 'O') {
				map[j][i] = 0;
				final_loc_x = j;
				final_loc_y = i;
			}
		}
	}
	/*
	cout << "\n\n";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << map[j][i];
		}
		cout << "\n";
	}
	*/
//	cout << "red xy " << red_x << " " << red_y << " blue xy " << blue_x << " " << blue_y << "\n";
	cout << ball_bfs(red_x, red_y, blue_x, blue_y);
	return 0;
}

int ball_bfs(int red_x, int red_y, int blue_x, int blue_y) {
	queue<pair<pair<int, int>, int>> qu;
	int red = red_x + red_y * width;
	int blue = blue_x + blue_y * width;
	qu.push({ {red,blue},0 });
	while (!qu.empty()) {
		int red_n = qu.front().first.first;
		int red_nx = red_n % width;
		int red_ny = red_n / width;
		int blue_n = qu.front().first.second;
		int blue_nx = blue_n % width;
		int blue_ny = blue_n / width;
		int cnt = qu.front().second;
		qu.pop();
		if (visit[red_n][blue_n] != -1)
			continue;
		visit[red_n][blue_n] = cnt;
//		cout << "visit " << visit[red_n][blue_n] << "\n";
		for (int i = 0; i < 4; i++) {
			pair<int, int> tmp = ball_move(red_nx, red_ny, blue_nx, blue_ny, i);
//			cout << "cnt " << cnt << " " << tmp.first % width << " " << tmp.first / width << " " <<
//				tmp.second % width << " " << tmp.second / width << "\n";
			if (tmp.first == INF)
				continue;
			else if (tmp.second == INF)
				return cnt + 1;
			qu.push({ { tmp.first,tmp.second },cnt + 1 });
		}
		if (cnt >= 10)
			return -1;
	}
	return -1;
}
pair<int, int> ball_move(int red_x, int red_y, int blue_x, int blue_y, int move) {
	bool red = false;
	bool blue = false;
	int tmp_x = red_x;
	int tmp_y = red_y;
	map[red_x][red_y] = 2;
	map[blue_x][blue_y] = 3;
	if (move % 2 == 0)
		while (map[red_x][red_y + dy[move]] == 0 || map[blue_x][blue_y + dy[move]] == 0) {
//			cout << red_x << " " << red_y << " " << blue_x << " " << blue_y << " \n";
			if (map[red_x][red_y + dy[move]] == 0) {
				map[red_x][red_y] = 0;
				red_y += dy[move];
				map[red_x][red_y] = 2;
			}
			if (map[blue_x][blue_y + dy[move]] == 0) {
				map[blue_x][blue_y] = 0;
				blue_y += dy[move];
				map[blue_x][blue_y] = 3;
			}
			if (red_x == final_loc_x && red_y == final_loc_y) {
				map[red_x][red_y] = 0;
				red_x = 0;
				red_y = 0;
				red = true;
			}
			else if (blue_x == final_loc_x && blue_y == final_loc_y) {
				map[blue_x][blue_y] = 0;
				map[red_x][red_y] = 0;
				return { INF,0 };
			}
		}
	else if (move % 2 == 1) {
		while (map[red_x + dx[move]][red_y] == 0 || map[blue_x + dx[move]][blue_y] == 0) {
			if (map[red_x + dx[move]][red_y] == 0) {
				map[red_x][red_y] = 0;
				red_x += dx[move];
				map[red_x][red_y] = 2;
			}
			if (map[blue_x + dx[move]][blue_y] == 0) {
				map[blue_x][blue_y] = 0;
				blue_x += dx[move];
				map[blue_x][blue_y] = 3;
			}
			if (red_x == final_loc_x && red_y == final_loc_y) {
				map[red_x][red_y] = 0;
				red_x = 0;
				red_y = 0;
				red = true;
			}
			else if (blue_x == final_loc_x && blue_y == final_loc_y) {
				map[blue_x][blue_y] = 0;
				map[red_x][red_y] = 0;
				return { INF,0 };
			}
		}
	}
	if (red == true)
		return { 0,INF };
	map[red_x][red_y] = 0;
	map[blue_x][blue_y] = 0;
	pair<int, int> result;
	result.first = red_x + red_y * width;
	result.second = blue_x + blue_y * width;
	return result;
}