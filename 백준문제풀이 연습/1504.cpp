#include<iostream>
#include<vector>
#include<queue>
#define INF 1e8

using namespace std;

vector<pair<int, int>> map[804];
int dist[804];
int N, E;

int sejun_dijkstra(int v, int k);
int first_dijkstra(int str);
void setMemory();

int main() {
	int startLoc, finalLoc, distance;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> startLoc >> finalLoc >> distance;
		map[startLoc].push_back(make_pair(finalLoc, distance));
		map[finalLoc].push_back(make_pair(startLoc, distance));
	}
	int V, K;
	cin >> V >> K;
	cout << sejun_dijkstra(V, K);
	return 0;
}


int sejun_dijkstra(int v, int k) {
	setMemory();
	int first_root = 0;
	int second_root = 0;
	int middle_root = 0;
	first_dijkstra(1);
	first_root = dist[v];
	second_root = dist[k];
	setMemory();
	first_dijkstra(N);
	first_root += dist[k];
	second_root += dist[v];
	setMemory();
	first_dijkstra(v);
	first_root += dist[k];
	second_root += dist[k];
	int result = min(first_root, second_root);
	if (first_root > INF || second_root > INF)
		return -1;
	return result;
}

int first_dijkstra(int str) {
	priority_queue<pair<int, int>> qu;
	dist[str] = 0;
	qu.push(make_pair(-dist[str], str));

	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		for (int i = 0; i < map[here].size(); i++) {
			int next = map[here][i].first;
			if (dist[here] + map[here][i].second < dist[next]) {
				dist[next] = dist[here] + map[here][i].second;
				qu.push(make_pair(-dist[next], next));
			}
		}
	}
	return 0;
}

void setMemory() {
	for (int i = 0; i < 804; i++) {
		dist[i] = INF;
	}
}