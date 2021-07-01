#include <iostream>
using namespace std;

int main() {
	char yootAnswer[5] = { 'E','A','B','C','D' };
	int answerNum = 0;
	int yootResult[4];
	for (int t = 0; t < 3; t++) {
		for (int i = 0; i < 4; i++) {
			cin >> yootResult[i];
			if (yootResult[i] == 0)
				answerNum += 1;
		}
		cout << yootAnswer[answerNum] << "\n";
		answerNum = 0;
	}
	return 0;
}