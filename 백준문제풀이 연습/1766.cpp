#include<iostream>
#include<vector>
#include<queue>
#define INF 40000
using namespace std;

vector<int> map[INF];
int N;
int is_root[INF];
int s_node[INF];

int problemBfs() {
	priority_queue<int> qu;
	vector<int> result;
	for (int i = 1; i <= N; i++)
		if (is_root[i] == true)
			qu.push(-i);
	while (!qu.empty()) {
		int node = -qu.top();
//		cout << "node" << node << ", ";
		qu.pop();
		result.push_back(node);
		for (int i = 0; i < map[node].size(); i++) {
			int next = map[node][i];
			s_node[next] -= 1;
			if (s_node[next] != 0)
				continue;
			else
				qu.push(-next);
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}

int main() {
	for (int i = 0; i < INF; i++)
		is_root[i] = true;
	cin >> N;
	int t = 0;
	cin >> t;
	int start;
	int end;
	for (int i = 0; i < t; i++) {
		cin >> start >> end;
		map[start].push_back(end);
		s_node[end] += 1;
		is_root[end] = false;
	}
	problemBfs();
	return 0;
}