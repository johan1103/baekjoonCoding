#include <iostream>
using namespace std;

int printImportance[100];
int printCount = 0;
int startPoint = 0;

int printSequence(int importance) {
	for(int i=printCount-1;i>=0;i--){
		if (importance == printImportance[i]) {
			for (int t = i; t >= 0; t--) {
				if (printImportance[t] > importance) {
					startPoint = t - 1;
				}
			}
		}
	}
}

int main() {
	int testCase = 0;

	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> printCount;
		for (int t = 0; t < printCount; t++) {
			cin >> printImportance[t];
		}
		
	}
	return 0;
}