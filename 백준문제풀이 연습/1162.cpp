#include<iostream>
#include<vector>
#include<queue>
#define INF 223372036854775800

using namespace std;

vector<pair<int, int>> map[10004];
long long dist[10004][22];
int visit[10004];
int N, M, K;

int roadCover_dijkstra() {
	priority_queue<pair<long long, pair<int, int>>> qu;
	dist[1][K] = 0;
	qu.push({ -dist[1][K],{1,K} });
	while (!qu.empty()) {
		int here = qu.top().second.first;
		int free_cnt = qu.top().second.second;
		long long here_cost = -qu.top().first;
		qu.pop();

		//???????
		if (dist[here][free_cnt] < here_cost) {
			continue;
		}
		for (int i = 0; i < map[here].size(); i++) {
			int next = map[here][i].first;
			long long next_cost = map[here][i].second;

			if (dist[here][free_cnt] + next_cost < dist[next][free_cnt]) {
				dist[next][free_cnt] = dist[here][free_cnt] + next_cost;
				qu.push({ -dist[next][free_cnt],{next,free_cnt} });
			}

			if (free_cnt > 0) {
				if (dist[here][free_cnt] < dist[next][free_cnt - 1]) {
					dist[next][free_cnt - 1] = dist[here][free_cnt];
					qu.push({ -dist[next][free_cnt - 1],{next,free_cnt - 1} });
				}
			}
		}
	}
	return 0;
}

void setMemory() {
	for (int i = 0; i < 10004; i++) {
		for (int j = 0; j < 22; j++) {
			dist[i][j] = INF;
		}
	}
}


int main() {
	setMemory();
	long long start_loc, final_loc, distance;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> start_loc >> final_loc >> distance;
		map[start_loc].push_back({ final_loc,distance });
		map[final_loc].push_back({ start_loc,distance });
	}
	roadCover_dijkstra();
	long long result = INF;
	for (int i = 0; i <= K; i++) {
		result = min(result, dist[N][i]);
	}
	cout << result;
	return 0;
}