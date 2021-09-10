#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>> startMap[10004];
vector<pair<int, int>> finalMap[10004];
int startDist[10004];
int finalDist[10004];

int party_dijkstra();
void setMemory();

int main() {

	cout << party_dijkstra();
	return 0;
}


int party_dijkstra() {
	int N, M, X;
	int startLoc, finalLoc, distance;
	setMemory();
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> startLoc >> finalLoc >> distance;
		startMap[startLoc].push_back(make_pair(finalLoc, distance));
		finalMap[finalLoc].push_back(make_pair(startLoc, distance));
	}

	priority_queue<pair<int, int>> qu;
	startDist[X] = 0;
	qu.push(make_pair(startDist[X], X));
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		for (int i = 0; i < startMap[here].size(); i++) {
			int next = startMap[here][i].first;
			if (startDist[here] + startMap[here][i].second < startDist[next]) {
				startDist[next] = startDist[here] + startMap[here][i].second;
				qu.push(make_pair(-startDist[next], next));
			}
		}
	}
	finalDist[X] = 0;
	qu.push(make_pair(finalDist[X], X));
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		for (int i = 0; i < finalMap[here].size(); i++) {
			int next = finalMap[here][i].first;
			if (finalDist[here] + finalMap[here][i].second < finalDist[next]) {
				finalDist[next] = finalDist[here] + finalMap[here][i].second;
				qu.push(make_pair(-finalDist[next], next));
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		result = max(result, startDist[i] + finalDist[i]);
	}
	return result;
}
void setMemory() {
	for (int i = 0; i < 10004; i++) {
		finalMap[i].clear();
		startMap[i].clear();
		finalDist[i] = INF;
		startDist[i] = INF;
	}
}