#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int numArr[1000004];
int arrSize = 0;

void sortArr() {
	int temp = -1;
	sort(numArr, numArr + arrSize);
	for (int i = 0; i < arrSize; i++) {
		if (temp == numArr[i])
			continue;
		cout << numArr[i] << "\n";
		temp = numArr[i];
	}

}

int main() {
	cin >> arrSize;
	for (int i = 0; i < arrSize; i++)
		cin >> numArr[i];
	sortArr();

	return 0;
}
