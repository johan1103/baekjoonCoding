#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> memory(100);

//바텀업 방식
void setMemory() {
	for (int i = 0; i < memory.size(); i++) {
		memory[i] = 0;
	}
	memory[0] = 1;
}

//낮은 숫자부터 채우기
//낮은 숫자부터 채우므로 계산이 겹칠일이 없음
//number함수의 인수로 숫자에 도달했다는 의미는 그 숫자의 경우의 수는 계산이 끝난것을 뜻함
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