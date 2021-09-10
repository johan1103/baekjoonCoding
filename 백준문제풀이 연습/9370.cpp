#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1e9
using namespace std;

vector<pair<int,int>> map[2004];
int dist[2004];
bool cross[2004];

void Circus_dijkstra();;
void setMemory();


int main() {
	int testCase = 0;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		setMemory();
		Circus_dijkstra();
		cout << "\n";
	}
	return 0;
}



void Circus_dijkstra() {
	int N, M, T;
	int S, G, H;
	int startLoc, finalLoc, distance;
	vector<int> finalLoc_list;
	cin >> N >> M >> T;
	cin >> S >> G >> H;
	for (int i = 1; i <= M; i++) {
		cin >> startLoc >> finalLoc >> distance;
		map[startLoc].push_back(make_pair(finalLoc, distance));
		map[finalLoc].push_back(make_pair(startLoc, distance));
	}
	for (int i = 0; i < T; i++) {
		cin >> finalLoc;
		finalLoc_list.push_back(finalLoc);
	}
	priority_queue<pair<int, int>> qu;
	dist[S] = 0;
	cross[S] = false;
	qu.push(make_pair(-dist[S], S));
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		int next = 0;
		for (int i = 0; i < map[here].size(); i++) {
			next = map[here][i].first;
			if (dist[here] + map[here][i].second <= dist[next]) {
				if (here == G && next == H || here == H && next == G) {
					cross[next] = true;
				}
				else if (dist[here] + map[here][i].second == dist[next]) {
					if (cross[here] == true) {
						cross[next] = true;
					}
					continue;
				}
				else
					cross[next] = cross[here];
				dist[next] = dist[here] + map[here][i].second;
				qu.push(make_pair(-dist[next], next));
				
			}
		}
	}
	sort(finalLoc_list.begin(), finalLoc_list.end());
	
	for (int i = 0; i < finalLoc_list.size(); i++) {
		int result = finalLoc_list[i];
		if (cross[result] == true) {
			cout << result << " ";
		}
	}
	/*
	for (int i = 1; i <= N; i++) {
		cout << "i " << i << " dist --- " << dist[i] << " " << cross[i] << "\n";
	}
	*/
}


void setMemory() {
	for (int i = 0; i < 2004; i++) {
		map[i].clear();
		dist[i] = INF;
		cross[i] = false;
	}
}