#include<iostream>
#include<vector>

using namespace std;

int map[509][509]; //���� �Ǵ� ���� �ִ� ũ��
int memory[509][509]; //�޸������̼� �� �޸𸮵� (���� ��ġ�� ���� �޸������̼��ҰŶ�)
int mapWidth; //�����Ǵ� ���� �ʺ�
int mapHeight; //�����Ǵ� ���� ����

const int dx[4] = { 0, 1, 0, -1 }; //��, ������, �Ʒ�, �������� �����̰� �� ��ǥ
const int dy[4] = { -1, 0, 1, 0 }; // ex) x��ǥ�� +dx[0], y��ǥ�� +dy[0] �ϸ� ���� �̵�.


int downTown(int nx, int ny) {
	if (memory[nx][ny] != -1) //�湮�� �� �ִ� ��ǥ�̸� ����� �޸𸮸� return
		return memory[nx][ny];
	if (nx == mapWidth && ny == mapHeight) {
		return 1; //�������� ����� ���� ������, ����� ���� �ϼ��� ���̹Ƿ� 1 return
	}
	int nowNum = map[nx][ny]; //map[nx][ny]�� ���ֻ���ؼ�, �򰥸��� �ʱ� ���� ������ ����
	int result = 0; //��� ����� ���� result�� �����ؼ� return
	for (int i = 0; i < 4; i++) { //�� ������ �Ʒ� �������� ���� ����� ���� ����� for��
		if (nx + dx[i] <= 0 || nx + dx[i] > mapWidth)
			continue;
		if (ny + dy[i] <= 0 || ny + dy[i] > mapHeight)
			continue;
		//���� ���� ����� continue�� ���� ó��
		if (map[nx + dx[i]][ny + dy[i]] < nowNum) {
			// ���� ��ǥ�� ���� ���� ��ġ�� ������ ��ǥ������ ũ�� ��� ȣ���ؼ� result�� ����
			result += downTown(nx + dx[i], ny + dy[i]);
		}
	}
	//�޸𸮿� ���Ϸ��� result�� ����
	memory[nx][ny] = result;
	return result;
}

//����Ǯ�� ���� �̸� �湮���� ���� �޸� -1�� �ʱ�ȭ
void setMemory() {
	for (int i = 0; i <= mapHeight; i++) {
		for (int j = 0; j <= mapWidth; j++) {
			memory[j][i] = -1;
			map[j][i] = 0;
		}
	}
}


int main() {
	cin >> mapHeight >> mapWidth;
	//�޸� �ʱ�ȭ
	setMemory();
	for (int i = 1; i <= mapHeight; i++) {
		for (int j = 1; j <= mapWidth; j++) {
			cin >> map[j][i];
		}
	}
	//1,1���� ���.
	cout << downTown(1, 1);

	return 0;
}