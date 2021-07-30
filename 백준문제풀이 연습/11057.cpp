#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�޸������̼��� �޸� memory[���ڿ���ȣ][(0~9)����]
int memory[1004][11];

void setMemory() {
	//memroy�� ���� -1�̸� �湮���� ���°����� ����
	for (int i = 0; i < 1004; i++) {
		for (int t = 0; t < 11; t++) {
			memory[i][t] = -1;
		}
	}
}

//return���� ���������� �� ������
int upperStair(int chiper, int nowNum) {
	//���� 9�� �Ѿ�� ���ڿ��� ���� �� �����Ƿ� 0�� ��ȯ
	if (nowNum > 9)
		return 0;
	//chiper���� 1�̸� ���ڿ��� �ϼ��Ǿ��ٴ� �ǹ��̹Ƿ� 1�� ��ȯ
	if (chiper == 1)
		return 1;
	//memory���� -1�� �ƴϸ� �̹� ���� ���̶�� ���̹Ƿ� ����� �� ��ȯ
	if (memory[chiper][nowNum] != -1)
		return memory[chiper][nowNum];
	//return�� ��ȯ�� ���� ���� ���ϱ�
	int ret = 0;
	//0~9������ ���� ���� �� �����Ƿ� ������ 10�� �Ѿ�� �����Լ����� 0 ��ȯ
	for (int plusNum = 0; plusNum < 10; plusNum++) {
		ret += upperStair(chiper - 1, nowNum + plusNum);
		//ret�� ���� ������ ������ �Ѿ�� ���ÿ����÷ο찡 �߻��� �� �����Ƿ�
		//�Ѿ�� ���� ��� �Լ����� %���
		ret %= 10007;
	}
	//�޸𸮿� ���� ����� ���
	memory[chiper][nowNum] = ret;
	return ret;
}

//�����Ҷ� ����ϴ� �Լ� (���۰��� 0~9�� �ϳ��� ������� �ϹǷ�)
int AllUpperStair(int chiper) {
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += upperStair(chiper, i);
		result %= 10007;
	}
	return result;
}




int main() {
	setMemory();
	int testCase = 0;
	cin >> testCase;
	cout << AllUpperStair(testCase);
	return 0;
}
