#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

vector<pair<int, int>> map[1004];
int dist[1004];
int beforeLoc[1004];
int N, M;

int solve_problem();
int second_dijkstra(int from, int to);
int first_dijkstra();
void setMemory();

int main() {
	//cout << solve_problem();
	int startLoc, finalLoc, distance;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> startLoc >> finalLoc >> distance;
		map[startLoc].push_back(make_pair(finalLoc, distance));
		map[finalLoc].push_back(make_pair(startLoc, distance));
	}
	cout << solve_problem();
	return 0;
}

int solve_problem() {
	int result = 0;
	int noMark = 0;
	int backTracking = N;
	beforeLoc[1] = -1;
	noMark = first_dijkstra();
	while (true) {
		int fin = backTracking;
		int srt = beforeLoc[backTracking];
		backTracking = beforeLoc[backTracking];
		if (backTracking == -1)
			break;
		int tmp = second_dijkstra(srt, fin);
		if (tmp == INF)
			return -1;
		result = max(result, tmp);
	}
	return result - noMark;
}


int second_dijkstra(int from, int to) {
	int tempDistance = 0;
	int tempDistanceLoc_from = 0;
	int tempDistanceLoc_to = 0;
	for (int i = 0; i < map[from].size(); i++) {
		if (map[from][i].first == to) {
			tempDistance = map[from][i].second;
			tempDistanceLoc_from = i;
			map[from][i].second = INF;
			break;
		}
	}
	for (int i = 0; i < map[to].size(); i++) {
		if (map[to][i].first == from) {
			tempDistanceLoc_to = i;
			map[from][i].second = INF;
			break;
		}
	}
	setMemory();
	priority_queue<pair<int, int>> qu;
	dist[1] = 0;
	qu.push(make_pair(-dist[1], 1));
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		for (int i = 0; i < map[here].size(); i++) {
			int next = map[here][i].first;
			if (dist[here] + map[here][i].second < dist[next]) {
				dist[next] = dist[here] + map[here][i].second;
				beforeLoc[next] = here;
				qu.push(make_pair(-dist[next], next));
			}
		}
	}
	map[from][tempDistanceLoc_from].second = tempDistance;
	map[to][tempDistanceLoc_to].second = tempDistance;
	return dist[N];
}


int first_dijkstra() {
	setMemory();
	priority_queue<pair<int, int>> qu;
	dist[1] = 0;
	qu.push(make_pair(-dist[1], 1));
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		for (int i = 0; i < map[here].size(); i++) {
			int next = map[here][i].first;
			if (dist[here] + map[here][i].second < dist[next]) {
				dist[next] = dist[here] + map[here][i].second;
				beforeLoc[next] = here;
				qu.push(make_pair(-dist[next], next));
			}
		}
	}
	return dist[N];
}

void setMemory() {
	for (int i = 0; i < 1004; i++) {
		dist[i] = INF;
	}
}