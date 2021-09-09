#include<iostream>
#include<vector>
#include<queue>

/*

백준 1005번문제와 거의 완벽하게 문제 유형이 동일


*/


using namespace std;

vector<int> map[509];
int value[509];
int visit[509];

int Sejun_craft(int here) {
	if (visit[here] != -1)
		return visit[here];

	int result = value[here];

	for (int i = 0; i < map[here].size(); i++) {
		int next = map[here][i];
		result = max(result, value[here] + Sejun_craft(next));
	}
	visit[here] = result;
	return result;
}
void setMemory() {
	for (int i = 0; i < 509; i++) {
		visit[i] = -1;
		value[i] = 0;
		map[i].clear();
	}
}


int main() {
	setMemory();
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
		int startLoc = 0;
		int finalLoc = 0;
		while (finalLoc != -1) {
			cin >> finalLoc;
			map[i].push_back(finalLoc);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << Sejun_craft(i) << "\n";
	}

	return 0;
}