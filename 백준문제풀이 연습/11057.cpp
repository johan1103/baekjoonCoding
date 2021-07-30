#include<iostream>
#include<string>
#include<vector>
using namespace std;

//메모이제이션할 메모리 memory[숫자열번호][(0~9)숫자]
int memory[1004][11];

void setMemory() {
	//memroy의 값이 -1이면 방문한적 없는값으로 설정
	for (int i = 0; i < 1004; i++) {
		for (int t = 0; t < 11; t++) {
			memory[i][t] = -1;
		}
	}
}

//return값은 오르막수의 총 가짓수
int upperStair(int chiper, int nowNum) {
	//값이 9를 넘어가면 숫자열을 만들 수 없으므로 0을 반환
	if (nowNum > 9)
		return 0;
	//chiper값이 1이면 숫자열이 완성되었다는 의미이므로 1을 반환
	if (chiper == 1)
		return 1;
	//memory값이 -1이 아니면 이미 계산된 값이라는 뜻이므로 저장된 값 반환
	if (memory[chiper][nowNum] != -1)
		return memory[chiper][nowNum];
	//return값 반환할 변수 전부 더하기
	int ret = 0;
	//0~9까지의 값을 더할 수 있으므로 더한후 10을 넘어가면 다음함수에서 0 반환
	for (int plusNum = 0; plusNum < 10; plusNum++) {
		ret += upperStair(chiper - 1, nowNum + plusNum);
		//ret의 값이 정수의 범위를 넘어가면 스택오버플로우가 발생할 수 있으므로
		//넘어가기 전에 모든 함수에서 %계산
		ret %= 10007;
	}
	//메모리에 나온 결과값 등록
	memory[chiper][nowNum] = ret;
	return ret;
}

//시작할때 사용하는 함수 (시작값을 0~9중 하나로 정해줘야 하므로)
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
