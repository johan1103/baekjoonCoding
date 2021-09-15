#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

vector<pair<int, int>> map[4004];
int fox_dist[4004];
int wolf_dist[4004][2];
int visit[4004][2];
int N, M;

int fox_dijkstra();
int wolf_dijkstra();
void setMemory();


int main() {
	int startLoc, finalLoc, distance;
	cin >> N >> M;
	setMemory();
	for (int i = 0; i < M; i++) {
		cin >> startLoc >> finalLoc >> distance;
		map[startLoc].push_back(make_pair(finalLoc, distance * 2));
		map[finalLoc].push_back(make_pair(startLoc, distance * 2));
	}
	fox_dijkstra();
	wolf_dijkstra();
	int result = 0;
	/*
	for (int i = 1; i <= N; i++) {
		cout << "fox " << fox_dist[i] << " wolf " << min(wolf_dist[i][0], wolf_dist[i][1]) << "\n";
	}
	*/
	for (int i = 1; i <= N; i++) {
		if (fox_dist[i] < min(wolf_dist[i][0], wolf_dist[i][1])) {
			result += 1;
		}
	}
	cout << result;
	return 0;
}


int fox_dijkstra() {
	fox_dist[1] = 0;
	priority_queue<pair<int, int>> qu;
	qu.push(make_pair(-fox_dist[1], 1));
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
	for (int i = 0; i < map[here].size(); i++) {
		int next = map[here][i].first;
			if (fox_dist[here] + map[here][i].second < fox_dist[next]) {
				fox_dist[next] = fox_dist[here] + map[here][i].second;
				qu.push(make_pair(-fox_dist[next], next));
			}
		}
	}
	return 0;
}
int wolf_dijkstra() {
	wolf_dist[1][0] = 0;
	priority_queue<pair<int, pair<int, int>>> qu;
	qu.push(make_pair(-wolf_dist[1][0], make_pair(1, 0)));
	while (!qu.empty()) {
		int here = qu.top().second.first;
		int run_rate = qu.top().second.second;
		if (visit[here][run_rate] != -1) {
			qu.pop();
			continue;
		}
		visit[here][run_rate] = 1;
		qu.pop();
		for (int i = 0; i < map[here].size(); i++) {
			int next = map[here][i].first;
			if (run_rate == 0) {
				if (wolf_dist[here][0] + (map[here][i].second/2) < wolf_dist[next][1]) {
					wolf_dist[next][1] = wolf_dist[here][0] + (map[here][i].second / 2);
					qu.push(make_pair(-wolf_dist[next][1], make_pair(next, 1)));
				}
			}
			else if (run_rate == 1) {
				if (wolf_dist[here][1] + (map[here][i].second * 2) < wolf_dist[next][0]) {
					wolf_dist[next][0] = wolf_dist[here][1] + (map[here][i].second * 2);
					qu.push(make_pair(-wolf_dist[next][0], make_pair(next, 0)));
				}
			}
		}
	}
	return 0;
}


void setMemory() {
	for (int i = 0; i <= N; i++) {
		visit[i][0] = -1;
		visit[i][1] = -1;
		fox_dist[i] = INF;
		wolf_dist[i][0] = INF;
		wolf_dist[i][1] = INF;
	}
	return;
}