#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// asci 1==49
int main() {
	int num = 0;
	int integer = 0;
	vector<char> changeNum;
	cin >> num >> integer;
	int temp = 1;
	char tempCh = 'a';

	while (num > 0) {
		temp = num % integer;
		num /= integer;
		tempCh = '0';
		if (temp < 10)
			tempCh += temp;
		else {
			tempCh = 'A';
			tempCh += temp - 10;
		}
		changeNum.push_back(tempCh);
	}
	for (int i = changeNum.size() - 1; i >= 0; i--)
		cout << changeNum[i];

	return 0;
}
