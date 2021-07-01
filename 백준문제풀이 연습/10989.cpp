#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	//¹Ø¿¡ ÀÌ ¼¼ÁÙ ½è´Ù°í ¸Â¾ÆÁü;;;;;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num[10001];
	int numSize = 0;
	int tempNum = 0;
	cin >> numSize;
	for (int i = 0; i < 10001; i++)
		num[i] = 0;
	for (int i = 0; i < numSize; i++) {
		cin >> tempNum;
		num[tempNum] += 1;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++) {
			cout << i << "\n";
		}
	}


	return 0;
}
