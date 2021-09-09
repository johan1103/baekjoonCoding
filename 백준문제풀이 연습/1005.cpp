#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

vector<int> map[1004];
int value[1004];
int visit[1004];

int AcmCraft_dfs(int here) {
//	cout << "here " << here << "\n";
	if (visit[here] != -1) {
		//해당 정점을 방문한 적이 있으면 계산된 값 return
		return visit[here];
	}
	visit[here] = value[here];
	//다음 정점이 아무것도 없을 때에도 현재 건물은 지어야 하므로
	//초기값을 현재 건물 짓는 시간으로 설정
	for (int i = 0; i < map[here].size(); i++) {
		//다음 정점들 중에서 시간이 가장 오래걸리는 정점을 경로로 선택
		int next = map[here][i];
		visit[here] = max(visit[here], value[here] + AcmCraft_dfs(next));
	}
	return visit[here];
}
//testcase가 여러개 이므로 자료 초기화 할 때 사용
void setMemory() {
	for (int i = 0; i < 1004; i++) {
		visit[i] = -1;
		value[i] = 0;
		map[i].clear();
	}
}

int main() {
	int testCase = 0;
	cin >> testCase;
	for (int testNum = 0; testNum < testCase; testNum++) {
		int N, K;
		int startLoc, finalLoc;
		vector<int>startList;
		setMemory();
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> value[i];
		}
		for (int i = 0; i < K; i++) {
			//탐색을 위해 문제와 반대로 그래프 설정
			cin >> startLoc >> finalLoc;
			map[finalLoc].push_back(startLoc);
		}
		cin >> finalLoc;
		cout << AcmCraft_dfs(finalLoc) << "\n";
	}
	return 0;
}