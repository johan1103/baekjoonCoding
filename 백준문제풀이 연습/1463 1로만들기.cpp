#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> CalculatedValue;

int makingOne(int nowValue) {
	if (nowValue == 1)
		return 0;
	if (CalculatedValue[nowValue] != -1)
		return CalculatedValue[nowValue];
	int result[3] = { 1000000,1000000,1000000 };
	int ret = -1;
	result[2] = makingOne(nowValue - 1) + 1;
	if (nowValue % 3 == 0) {
		result[0] = makingOne(nowValue / 3) + 1;
	}
	if (nowValue % 2 == 0) {
		result[1] = makingOne(nowValue / 2) + 1;
	}
	ret = min(result[0], min(result[1], result[2]));
	CalculatedValue[nowValue] = ret;
	return ret;
}

int main() {

	for (int i = 0; i <= 1000010; i++) {
		CalculatedValue.push_back(-1);
	}
	int num = 0;
	cin >> num;
	int answer = makingOne(num);
	cout << answer;


	return 0;
}