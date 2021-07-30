#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�޸������̼� �޸� memory[���ڿ���ȣ][���ڰ���(0~9)]
int memory[104][11];
void setMemory() {
	//�湮���� ������ ���ڵ��� -1�� ����
	for (int i = 0; i < 11; i++) {
		for (int t = 0; t < 104; t++) {
			memory[t][i] = -1;
		}
	}
}
//��ܼ����� �� ������ return���ִ� �Լ�
int stairNum(int chiper, int nowNum) {
	//�Լ��� ������ nowNum(���޹��� ���� ����)�� 
	//0~9���� ���ڶ�� ���ڿ��� �� �� �����Ƿ� 0�� ��ȯ
	if (nowNum >= 10 || nowNum <= -1)
		return 0;
	//chiper�� 1�̸� ���ڿ� �ϼ�
	if (chiper == 1)
		return 1;
	//memroy�� ���� -1�� �ƴϸ� �̹� ���� ���̹Ƿ� ����� �� return
	if (memory[chiper][nowNum] != -1)
		return memory[chiper][nowNum];
	//return�� ������� ������ ���� ����
	int ret = 0;
	//�߰��� ����� ���� 1000000000�� �Ѿ ���ÿ����÷ο찡 �߻��ϸ� �������� ���Ƿ�
	//��� �Լ����� 1000000000�� �̸� %������༭ ���ÿ����÷ο츦 ����
	ret = (stairNum(chiper - 1, nowNum - 1) + stairNum(chiper - 1, nowNum + 1)) % 1000000000;
	memory[chiper][nowNum] = ret;
	return ret;
}

int AllStairNum(int chiper) {
	int result = 0;
	//���ڿ� ������ ù��° ��(0~9)���� ����� �� ����ϱ� ���� for��
	for (int i = 1; i < 10; i++) {
		result += stairNum(chiper, i);
		//		cout << result << "\n";
		result = result % 1000000000;
		//	cout << "fix result : " << result << "\n";
	}
	return result;
}




int main() {
	setMemory();
	int testCase = 0;
	cin >> testCase;
	cout << AllStairNum(testCase);

	return 0;
}
