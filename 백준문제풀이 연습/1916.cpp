#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

vector<pair<int, int>> map[1004];
int dist[1004];
int memory[1004];
int city;

void setMemory() {
	for (int i = 0; i <= city; i++) {
		//거리는 최대값으로 설정 (계속 최소값을 찾아서 갱신해야하기 때문)
		dist[i] = INF;
		//방문한적 없는 정점의 memory는 -1값을 가짐
		memory[i] = -1;
	}
	return;
}

int main() {
	int result = 0;
	cin >> city;
	int bus = 0;
	cin >> bus;
	int startLoc;
	int finalLoc;
	int cost;
	// (도착위치,가는비용)의 쌍으로 vector베열에 push_back.
	// 결과적으로 vector[i]는 i점에서 갈 수 있는 정점과 비용이의 쌍이 저장되어 있는 vector
	for (int i = 0; i < bus; i++) {
		cin >> startLoc;
		cin >> finalLoc;
		cin >> cost;
		map[startLoc].push_back(make_pair(finalLoc, cost));
	}
	setMemory();
	cin >> startLoc;
	cin >> finalLoc;

	//시작위치는 제자리이므로 비용이 0
	dist[startLoc] = 0;
	//방문할 목록인 우선순위 큐 선언
	priority_queue<pair<int, int>> qu;
	//시작위치 push.
	qu.push(make_pair(0, startLoc));
	while (!qu.empty()) {
		//here = 방문하고있는 정점
		int here = qu.top().second;
		if (memory[here] != -1) {
			//방분한 적이 있는 정점이면 이미 계산이 완료된 정점이므로 continue
			qu.pop();
			continue;
		}
		//방문표시
		memory[here] = 0;
		//현재 방문하고 있는 정점이 목표지점이면 문제 해결
		if (here == finalLoc) {
			//qu의 첫번째 값은 최단거리 값이므로 결과에 저장후 break
			//첫번째 값은 우선순위 큐 값이 큰순서로 정렬되어서 -형태로 저장되어있음
			//따라서 원래의 값을 얻으려면 -부호를 붙여줘야함
			result = -qu.top().first;
			break;
		}
		//방문했으므로 우선순위큐에서 제거
		qu.pop();
		//현재 방문한 정점에서 인접한 칸 검사
		for (int i = 0; i < map[here].size(); i++) {
			//next = 다음 정점후보
			int next = map[here][i].first;
			//다음 정점후보의 가중치 + 현재정점의 최소거리가 저장되어있는 다음정점의 최소거리보다 작으면
			//새로운 최소경로를 찾은것이므로 우선순위 큐에 push
			if (dist[here] + map[here][i].second < dist[next]) {
				dist[next] = dist[here] + map[here][i].second;
				qu.push(make_pair(-dist[next], next));
			}
		}
	}
	//모든 계산이 끝나면 result가 최소 비용임
	cout<< result;
	return 0;
}