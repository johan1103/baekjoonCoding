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
		//�Ÿ��� �ִ밪���� ���� (��� �ּҰ��� ã�Ƽ� �����ؾ��ϱ� ����)
		dist[i] = INF;
		//�湮���� ���� ������ memory�� -1���� ����
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
	// (������ġ,���º��)�� ������ vector������ push_back.
	// ��������� vector[i]�� i������ �� �� �ִ� ������ ������� ���� ����Ǿ� �ִ� vector
	for (int i = 0; i < bus; i++) {
		cin >> startLoc;
		cin >> finalLoc;
		cin >> cost;
		map[startLoc].push_back(make_pair(finalLoc, cost));
	}
	setMemory();
	cin >> startLoc;
	cin >> finalLoc;

	//������ġ�� ���ڸ��̹Ƿ� ����� 0
	dist[startLoc] = 0;
	//�湮�� ����� �켱���� ť ����
	priority_queue<pair<int, int>> qu;
	//������ġ push.
	qu.push(make_pair(0, startLoc));
	while (!qu.empty()) {
		//here = �湮�ϰ��ִ� ����
		int here = qu.top().second;
		if (memory[here] != -1) {
			//����� ���� �ִ� �����̸� �̹� ����� �Ϸ�� �����̹Ƿ� continue
			qu.pop();
			continue;
		}
		//�湮ǥ��
		memory[here] = 0;
		//���� �湮�ϰ� �ִ� ������ ��ǥ�����̸� ���� �ذ�
		if (here == finalLoc) {
			//qu�� ù��° ���� �ִܰŸ� ���̹Ƿ� ����� ������ break
			//ù��° ���� �켱���� ť ���� ū������ ���ĵǾ -���·� ����Ǿ�����
			//���� ������ ���� �������� -��ȣ�� �ٿ������
			result = -qu.top().first;
			break;
		}
		//�湮�����Ƿ� �켱����ť���� ����
		qu.pop();
		//���� �湮�� �������� ������ ĭ �˻�
		for (int i = 0; i < map[here].size(); i++) {
			//next = ���� �����ĺ�
			int next = map[here][i].first;
			//���� �����ĺ��� ����ġ + ���������� �ּҰŸ��� ����Ǿ��ִ� ���������� �ּҰŸ����� ������
			//���ο� �ּҰ�θ� ã�����̹Ƿ� �켱���� ť�� push
			if (dist[here] + map[here][i].second < dist[next]) {
				dist[next] = dist[here] + map[here][i].second;
				qu.push(make_pair(-dist[next], next));
			}
		}
	}
	//��� ����� ������ result�� �ּ� �����
	cout<< result;
	return 0;
}