#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�޸������̼��� ���� �޸�
long long memory[100];
//�湮���� ���� ����� ���� -1�� ����
void setMemory();
//���� ���ڰ� 1�� ������������ �Լ�
long long binaryZero(int n);
//���� ���ڰ� 0���� ������������ �Լ�
long long binaryFriend(int n);
//�����Ҷ� ����ϴ� �Լ�
long long startBinary(int n);


int main() {
	setMemory();

	int testCase = 0;
	cin >> testCase;
	cout << startBinary(testCase);

	return 0;
}
void setMemory() {
	//���� -1�� �ʱ�ȭ
	for (int i = 0; i < 100; i++)
		memory[i] = -1;
}
long long binaryZero(int n) {
	//���� ���ڰ� 1�̿����Ƿ� �̹����ڴ� ������ 0�̴�.
	//���� �޸������̼��� �� �ʿ䰡 ����
	//���ڿ��� �ϼ��ϸ� 1 return
	if (n == 0)
		return 1;
	//�̹����ڰ� 0�̹Ƿ� �������ڴ� 0�̳� 1�� ������ �����ϹǷ� binaryFriend�Լ� ȣ��
	return binaryFriend(n - 1);
}
long long binaryFriend(int n) {
	//���ڿ��� �ϼ������� 1 return
	if (n == 0)
		return 1;
	//�湮�� ���� ������ ����� �޸𸮸� return
	if (memory[n] != -1) {
		return memory[n];
	}
	//���� ���ڰ� 0�̿����Ƿ� 1�� �����ϴ� ���� 0�� �����ϴ� ��� �Ѵ� ���ؼ� return
	//�ϴ� ���ÿ� �޸𸮿� ����
	memory[n] = binaryFriend(n - 1) + binaryZero(n - 1);
	return memory[n];

}

long long startBinary(int n) {
	//�����Ҷ� ������ 1�̿��� �ϹǷ� binaryZero�Լ� ȣ��
	return binaryZero(n - 1);
}

