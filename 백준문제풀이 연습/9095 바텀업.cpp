#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> memory(100);

//���Ҿ� ���
void setMemory() {
	for (int i = 0; i < memory.size(); i++) {
		memory[i] = 0;
	}
	memory[0] = 1;
}

//���� ���ں��� ä���
//���� ���ں��� ä��Ƿ� ����� ��ĥ���� ����
//number�Լ��� �μ��� ���ڿ� �����ߴٴ� �ǹ̴� �� ������ ����� ���� ����� �������� ����
void number(int n) {
	memory[n + 1] += memory[n];
	memory[n + 2] += memory[n];
	memory[n + 3] += memory[n];
	return;
}

int main() {
	int count = 0;
	int parameter = 0;
	setMemory();
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> parameter;
		for (int j = 0; j < parameter; j++) {
			number(j);
		}
		cout << memory[parameter] << "\n";
		setMemory();
	}
	return 0;
}