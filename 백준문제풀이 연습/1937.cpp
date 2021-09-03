#include<iostream>
#include<vector>

using namespace std;

int map[509][509]; //�������� ���õ� �� (�ִ�ũ�� 500�� ���缭 ���� ���� �ְ� ����)
int memory[509][509]; //�޸������̼� �� �޸�

int mapHeight; //���� ����
int mapWidth; //���� �ʺ� (���� ���� �Ҷ��� ������ ���簢���ΰ� �˾���.....)

//���� �����¿�� �̵��� ��, ���ϰ� �ϱ� ���� dx,dy
//ex) x+dx[0], y+dy[0]�ϸ� ������ġ���� ��ĭ ����, x+dx[1], y+dy[1]�ϸ� ��ĭ ���������� �����ΰ���
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int pandaRoot(int nx, int ny) {//nx, ny�� ���� �Ǵٰ� �ִ� x,y��ǥ
	//�湮���� ������ ����� �޸� return
	if (memory[nx][ny] != -1)
		return memory[nx][ny];
	//result�� return�� �����, �ϴ� �湮���� ����, �����Ѱ��� ����̴� 1�� ����
	int result = 1;
	for (int i = 0; i < 4; i++) {
		//dx, dy�� 4���� ����� ���� �������� ��θ� Ȯ���ϱ� ���� 4���ݺ��ϴ� for��
		if (nx + dx[i] <= 0 || nx + dx[i] > mapWidth)
			continue;
		if (ny + dy[i] <= 0 || ny + dy[i] > mapHeight)
			continue;
		//���� continue�� ���� ���� ��������� ���� ó��
		if (map[nx][ny] < map[nx + dx[i]][ny + dy[i]]) {
			//���� ���������� �볪���� ���� ���� �ִ� ������ �볪������ ���ٸ�
			result = max(result, 1 + pandaRoot(nx + dx[i], ny + dy[i]));
			//�ش� ��η� ���� �� �湮�� ĭ���� ������� ��ϵ� �ִ밪�� ���ؼ� �ִ밪 ���ϱ�
		}
	}
	//��� ���� result�� �޸𸮿� ����
	memory[nx][ny] = result;
	return result;
}

//������ Ǯ�� ���� �̸� memory���� -1��, map�� 0���� �ʱ�ȭ
void setMemory() {
	for (int i = 0; i <= mapHeight; i++) {
		for (int j = 0; j <= mapWidth; j++) {
			memory[j][i] = -1;
			map[j][i] = 0;
		}
	}
	return;
}


int main() {
	int result = 0;
	cin >> mapHeight;
	mapWidth = mapHeight;
	setMemory();
	for (int i = 1; i <= mapHeight; i++) {
		for (int j = 1; j <= mapWidth; j++) {
			cin >> map[j][i];
		}
	}
	//��� ĭ���� ������ ���鼭 �ִ��� ���ؾ� �ϹǷ� 2�� for��
	for (int i = 1; i <= mapHeight; i++) {
		for (int j = 1; j <= mapWidth; j++) {
			result = max(result, pandaRoot(j, i));
		}
	}
	cout << result;
	return 0;
}