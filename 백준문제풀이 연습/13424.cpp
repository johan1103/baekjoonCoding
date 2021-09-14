#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>> map[104];
int dist[104];
int N, M, K;
vector<int> friendLoc;

int Harry_dijkstra(int startLoc) {
	dist[startLoc] = 0;
	priority_queue<pair<int, int>> qu;
	qu.push(make_pair(-dist[startLoc], startLoc));

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
	int result = 0;
	for (int i = 0; i < friendLoc.size(); i++) {
		result += dist[friendLoc[i]];
	}
	return result;
}
void setMemory() {
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
	return;
}



int main() {
	int testCase = 0;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		for (int i = 0; i <= N; i++) {
			map[i].clear();
		}
		friendLoc.clear();
		int startLoc, finalLoc, distance;
		int friends;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> startLoc >> finalLoc >> distance;
			map[startLoc].push_back(make_pair(finalLoc, distance));
			map[finalLoc].push_back(make_pair(startLoc, distance));
		}
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> friends;
			friendLoc.push_back(friends);
		}
		int result = INF;
		int resultRoom = 0;
		for (int i = 1; i <= N; i++) {
			setMemory();
			int tmp = Harry_dijkstra(i);
			if (tmp < result) {
				result = tmp;
				resultRoom = i;
			}
		}
		cout << resultRoom << "\n";
	}
	return 0;
}