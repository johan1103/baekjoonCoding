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
		return visit[here];
	}
	visit[here] = value[here];
	for (int i = 0; i < map[here].size(); i++) {
		int next = map[here][i];
		visit[here] = max(visit[here], value[here] + AcmCraft_dfs(next));
	}
	return visit[here];
}
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
			cin >> startLoc >> finalLoc;
			map[finalLoc].push_back(startLoc);
		}
		/*
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < map[i].size(); j++) {
				cout << i << " " << map[i][j] << "\n";
			}
		}
		*/
		cin >> finalLoc;
		cout << AcmCraft_dfs(finalLoc) << "\n";
	}
	return 0;
}