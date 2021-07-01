#include <iostream>
#include<algorithm>
#include <vector>
//예제도 다 되는데 ideone에서 이상한 값 나오고 백준에서도 %가 아예안나오는거 보면 알고리즘문제가 아니라
//코드문제인듯
using namespace std;
int yootRelate[33][2];
int yootScore[33];


void setBoard();
void setScore();
int moveYoot(int start, int leftDice, int nowLocate);
int DiceYoot(int dice[10], int nowDice, int yootState[4]);


int main() {

	int dice[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int yootState[4] = { 0,0,0,0 };
	setBoard();
	setScore();

	for (int i = 0; i < 10; i++) {
		dice[i] = 0;
		cin >> dice[i];
	}
	int result = 0;

	result = DiceYoot(dice, 0, yootState);
	cout << result;
}


void setBoard() {
	yootRelate[0][0] = 1;
	for (int i = 1; i < 33; i++) {
		yootRelate[i][0] = i + 1;
		yootRelate[i][1] = 0;
	}
	yootRelate[5][1] = 21;
	yootRelate[10][1] = 24;
	yootRelate[15][1] = 26;
	yootRelate[23][0] = 29;
	yootRelate[25][0] = 29;
	yootRelate[28][0] = 29;
	yootRelate[31][0] = 20;
	yootRelate[20][0] = 32;
}
void setScore() {
	for (int i = 1; i <= 14; i++) {
		yootScore[i] = i * 2;
	}
	int t = 0;
	for (int i = 15; i <= 19; i++) {
		yootScore[i] = 30 + t * 2;
		t += 1;
	}
	t = 1;
	yootScore[20] = 40;
	for (int i = 21; i <= 23; i++) {
		yootScore[i] = 10 + t * 3;
		t += 1;
	}
	t = 0;
	for (int i = 24; i <= 25; i++) {
		yootScore[i] = 22 + t * 2;
		t += 1;
	}
	t = 0;
	yootScore[26] = 28;
	yootScore[27] = 27;
	yootScore[28] = 26;
	for (int i = 29; i <= 31; i++) {
		yootScore[i] = 25 + t * 5;
		t += 1;
	}
	yootScore[32] = 0;
	return;
}

int moveYoot(int start, int leftDice, int nowLocate) {
	if (leftDice == 0 || nowLocate == 32)
		return nowLocate;
	if (start == 1) {
		if (nowLocate == 5 || nowLocate == 10 || nowLocate == 15) {
			return moveYoot(0, leftDice - 1, yootRelate[nowLocate][1]);
		}
	}
	return moveYoot(0, leftDice - 1, yootRelate[nowLocate][0]);
}



int DiceYoot(int dice[10], int nowDice, int yootState[4]) {
	if (nowDice == 10)
		return 0;
	int ret = 0;
	int temp = 0;
	int maxResult;
	for (int i = 0; i < 4; i++) {
		bool overLap = false;
		if (yootState[i] == 32) {
			continue;
		}
		ret = moveYoot(1, dice[nowDice], yootState[i]);
		if (ret != 32) {
			for (int t = 0; t < 4; t++) {
				if (ret == yootState[t]) {
					overLap = true;
					break;
				}
			}
			if (overLap == true) {
				continue;
			}
		}
		temp = yootState[i];
		yootState[i] = ret;
		maxResult = max(maxResult, DiceYoot(dice, nowDice + 1, yootState) + yootScore[ret]);
		yootState[i] = temp;
	}
	return maxResult;
}
