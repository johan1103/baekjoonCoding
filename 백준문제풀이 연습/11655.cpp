#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*
아스키 코드  공백: 32 a: 97 A: 65 0: 48
*/

void menu(char& code) {
	int asci = int(code);
	if (asci >= 97 && asci <= 122) {
		asci += 13;
		asci %= 123;
		if (asci <= 97)
			asci = 97 + asci;
		code = asci;
		return;
	}
	else if (asci >= 65 && asci <= 90) {
		asci += 13;
		asci %= 91;
		if (asci <= 66)
			asci = 65 + asci;
		code = asci;
	}
	else {
		return;
	}
}

int main() {
	string codeSen;
	getline(cin, codeSen);
	for (int i = 0; i < codeSen.size(); i++) {
		menu(codeSen[i]);
		cout << codeSen[i];
	}
	cout << "\n";

	return 0;
}
