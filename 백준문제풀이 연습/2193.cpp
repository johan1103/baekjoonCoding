#include<iostream>
#include<string>
#include<vector>
using namespace std;

//메모이제이션을 위한 메모리
long long memory[100];
//방문하지 않은 경우의 수를 -1로 설정
void setMemory();
//앞의 숫자가 1로 정해졌을때의 함수
long long binaryZero(int n);
//앞의 숫자가 0으로 정해졌을때의 함수
long long binaryFriend(int n);
//시작할때 사용하는 함수
long long startBinary(int n);


int main() {
	setMemory();

	int testCase = 0;
	cin >> testCase;
	cout << startBinary(testCase);

	return 0;
}
void setMemory() {
	//전부 -1로 초기화
	for (int i = 0; i < 100; i++)
		memory[i] = -1;
}
long long binaryZero(int n) {
	//전의 숫자가 1이였으므로 이번숫자는 무조건 0이다.
	//따라서 메모이제이션을 할 필요가 없다
	//문자열을 완성하면 1 return
	if (n == 0)
		return 1;
	//이번숫자가 0이므로 다음숫자는 0이나 1중 선택이 가능하므로 binaryFriend함수 호출
	return binaryFriend(n - 1);
}
long long binaryFriend(int n) {
	//문자열을 완성했으면 1 return
	if (n == 0)
		return 1;
	//방문한 적이 있으면 저장된 메모리를 return
	if (memory[n] != -1) {
		return memory[n];
	}
	//전의 숫자가 0이였으므로 1을 선택하는 경우와 0을 선택하는 경우 둘다 더해서 return
	//하는 동시에 메모리에 저장
	memory[n] = binaryFriend(n - 1) + binaryZero(n - 1);
	return memory[n];

}

long long startBinary(int n) {
	//시작할땐 무조건 1이여야 하므로 binaryZero함수 호출
	return binaryZero(n - 1);
}

