#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

vector<pair<int, int>> map[10004];
vector<int> M, S;
int mac_dist[10004];
int star_dist[10004];
int V, E;
int X, Y;

int home_dijkstra();
int mac_dijkstra();
int star_dijkstra();
void setMemory();

int main() {
	setMemory();
	cin >> V >> E;
	int startLoc, finalLoc, distance;
	for (int i = 0; i < E; i++) {
		cin >> startLoc >> finalLoc >> distance;
		map[startLoc].push_back({ finalLoc,distance });
		map[finalLoc].push_back({ startLoc,distance });
	}
	int M_num;
	int S_num;
	cin >> M_num >> X;
	for (int i = 0; i < M_num; i++) {
		int tmp;
		cin >> tmp;
		M.push_back(tmp);
	}
	cin >> S_num >> Y;
	for (int i = 0; i < S_num; i++) {
		int tmp;
		cin >> tmp;
		S.push_back(tmp);
	}
	cout << home_dijkstra();
	return 0;
}



int home_dijkstra() {
	mac_dijkstra();
	star_dijkstra();
	int result = INF;
	for (int i = 1; i <= V; i++) {
//		cout << i << " " << mac_dist[i] << " " << star_dist[i];
		if (mac_dist[i] == 0 || star_dist[i] == 0)
			continue;
		if (mac_dist[i] <= X && star_dist[i] <= Y) {
			result = min(result, mac_dist[i] + star_dist[i]);
		}
	}
	if (result == INF)
		return -1;
	return result;
}

int mac_dijkstra() {
	priority_queue < pair<int, int>> qu;
	for (int i = 0; i < M.size(); i++) {
		mac_dist[M[i]] = 0;
		qu.push({ -mac_dist[M[i]],M[i] });
	}
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		for (int i = 0; i < map[here].size(); i++) {
			int next = map[here][i].first;
			int next_cost = map[here][i].second;
			if (mac_dist[here] + next_cost < mac_dist[next]) {
				mac_dist[next] = mac_dist[here] + next_cost;
				qu.push({ -mac_dist[next],next });
			}
		}
	}
	return 0;
}

int star_dijkstra() {
	priority_queue < pair<int, int>> qu;
	for (int i = 0; i < S.size(); i++) {
		star_dist[S[i]] = 0;
		qu.push({ -star_dist[S[i]],S[i] });
	}
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		for (int i = 0; i < map[here].size(); i++) {
			int next = map[here][i].first;
			int next_cost = map[here][i].second;
			if (star_dist[here] + next_cost < star_dist[next]) {
				star_dist[next] = star_dist[here] + next_cost;
				qu.push({ -star_dist[next],next });
			}
		}
	}
	return 0;
}

void setMemory() {
	for (int i = 0; i < 10004; i++) {
		mac_dist[i] = INF;
		star_dist[i] = INF;
	}
}
