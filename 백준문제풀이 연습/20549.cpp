#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int map[55][55];
int dist[55][55][5];
int N, M;
int knight_cost, bishop_cost, rook_cost;
vector<pair<int, int>> food_loc;

const int knight_dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
const int knight_dy[8] = { -2,-1,1,2,2,1,-1,-2 };

const int bishop_dx[4] = { 1,1,-1,-1 };
const int bishop_dy[4] = { -1,1,1,-1 };

const int rook_dx[4] = { 0,1,0,-1 };
const int rook_dy[4] = { -1,0,1,0 };


int duck_dijkstra(int start_loc_x,int start_loc_y,int duck_food) {
	dist[start_loc_x][start_loc_y][duck_food] = 0;
	priority_queue<pair<int, pair<int, int>>> qu;;
	qu.push({ -dist[start_loc_x][start_loc_y][duck_food],{start_loc_x,start_loc_y} });
	
	while (!qu.empty()) {
		const int here_x = qu.top().second.first;
		const int here_y = qu.top().second.second;
		const int here_cost = -qu.top().first;
		qu.pop();
		if (dist[here_x][here_y][duck_food] < here_cost)
			continue;
		for (int i = 0; i < 4; i++) {
			int next_x = here_x;
			int next_y = here_y;
			while (true) {
				next_x += bishop_dx[i];
				next_y += bishop_dy[i];
				if (next_x >= N || next_y >= N || next_x < 0 || next_y < 0)
					break;
				if (dist[here_x][here_y][duck_food] + bishop_cost < dist[next_x][next_y][duck_food]) {
					dist[next_x][next_y][duck_food] = dist[here_x][here_y][duck_food] + bishop_cost;
					qu.push({ -dist[next_x][next_y][duck_food],{next_x,next_y} });
				}
			}
			next_x = here_x;
			next_y = here_y;
			while (true) {
				next_x += rook_dx[i];
				next_y += rook_dy[i];
				if (next_x >= N || next_y >= N || next_x < 0 || next_y < 0)
					break;
				if (dist[here_x][here_y][duck_food] + rook_cost < dist[next_x][next_y][duck_food]) {
					dist[next_x][next_y][duck_food] = dist[here_x][here_y][duck_food] + rook_cost;
					qu.push({ -dist[next_x][next_y][duck_food],{next_x,next_y} });
				}
			}
		}
		for (int i = 0; i < 8; i++) {
			int next_x = here_x + knight_dx[i];
			int next_y = here_y + knight_dy[i];
			if (next_x >= N || next_y >= N || next_x < 0 || next_y < 0)
				continue;
			if (dist[here_x][here_y][duck_food] + knight_cost < dist[next_x][next_y][duck_food]) {
				dist[next_x][next_y][duck_food] = dist[here_x][here_y][duck_food] + knight_cost;
				qu.push({ -dist[next_x][next_y][duck_food],{next_x,next_y} });
			}
		}
	}
	return 0;
}

int visit[5] = { -1,-1,-1,-1,-1 };
int duck_dfs(int food_num) {
	visit[food_num] = 0;
	int result = INF;
	for (int i = 1; i <= M; i++) {
		if (visit[i] == 0) continue;
		int x = food_loc[i].first;
		int y = food_loc[i].second;
		result = min(result, dist[x][y][food_num] + duck_dfs(i));
	}
	visit[food_num] = -1;
	if (result == INF)
		return 0;
	return result;
}


void setMemory() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			for (int m = 0; m < 5; m++) {
				dist[j][i][m] = INF;
			}
			map[j][i] = 0;
		}
	}
}

int main() {
	setMemory();
	cin >> N;
	cin >> knight_cost >> bishop_cost >> rook_cost;
	int start_loc_x, start_loc_y;
	cin >> start_loc_x >> start_loc_y;
	food_loc.push_back({ start_loc_x,start_loc_y });
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		food_loc.push_back({ x,y });
	}
	for (int i = 0; i < food_loc.size(); i++) {
		int x = food_loc[i].first;
		int y = food_loc[i].second;
		duck_dijkstra(x, y, i);
	}
	cout << duck_dfs(0);
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dist[j][i][0] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dist[j][i][1] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dist[j][i][2] << " ";
		}
		cout << "\n";
	}
	*/
	return 0;
}