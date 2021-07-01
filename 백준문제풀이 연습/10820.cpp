#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*
아스키 코드  공백: 32 a: 97 A: 65 0: 48
*/

void menu(int store[4], char a) {
	int asci = int(a);
	if (asci == 32)
		store[3] += 1;
	else if (asci >= 48 && asci <= 57)
		store[2] += 1;
	else if (asci >= 65 && asci <= 90)
		store[1] += 1;
	else if (asci >= 97 && asci <= 122)
		store[0] += 1;
	return;
}

int main() {
	int store[4] = { 0,0,0,0 };
	string sen;
	while (1) {
		getline(cin, sen);
		if (sen.length() == 0)
			break;
		for (int i = 0; i < sen.length(); i++) {
			menu(store, sen[i]);
		}
		for (int i = 0; i < 4; i++)
			cout << store[i] << " ";
		cout << "\n";
		for (int i = 0; i < 4; i++)
			store[i] = 0;
	}
	return 0;
}
