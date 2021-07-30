#include<iostream>
#include<string>
#include<vector>
using namespace std;

//메모이제이션 메모리 memory[숫자열번호][숫자개수(0~9)]
int memory[104][11];
void setMemory() {
	//방문안한 깊이의 숫자들을 -1로 설정
	for (int i = 0; i < 11; i++) {
		for (int t = 0; t < 104; t++) {
			memory[t][i] = -1;
		}
	}
}
//계단숫자의 총 개수를 return해주는 함수
int stairNum(int chiper, int nowNum) {
	//함수의 인자인 nowNum(전달받은 현재 숫자)가 
	//0~9밖의 숫자라면 숫자열이 될 수 없으므로 0을 반환
	if (nowNum >= 10 || nowNum <= -1)
		return 0;
	//chiper가 1이면 숫자열 완성
	if (chiper == 1)
		return 1;
	//memroy의 값이 -1이 아니면 이미 계산된 값이므로 저장된 값 return
	if (memory[chiper][nowNum] != -1)
		return memory[chiper][nowNum];
	//return할 결과값을 저장할 변수 선언
	int ret = 0;
	//중간에 계산한 값이 1000000000을 넘어서 스택오버플로우가 발생하면 계산오류가 나므로
	//모든 함수마다 1000000000을 미리 %계산해줘서 스택오버플로우를 방지
	ret = (stairNum(chiper - 1, nowNum - 1) + stairNum(chiper - 1, nowNum + 1)) % 1000000000;
	memory[chiper][nowNum] = ret;
	return ret;
}

int AllStairNum(int chiper) {
	int result = 0;
	//문자열 시작할 첫번째 값(0~9)별로 경우의 수 계산하기 위한 for문
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
