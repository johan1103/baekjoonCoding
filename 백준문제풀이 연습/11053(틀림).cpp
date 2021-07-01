#include<iostream>
#include<string>
#include<vector>
using namespace std;

int memory[1004];
void setMemory() {
	for (int i = 0; i < 1004; i++)
		memory[i] = -1;
}

int longestArr(int num, vector<int>& leftArr) {
	cout << num << " ";
	int ret = 0;
	int arrSize = leftArr.size();
	if (arrSize == 0)
		return 0;
	if (leftArr.back() <= num) {
		int temp = leftArr.back();
		leftArr.pop_back();
		ret = longestArr(num, leftArr);
		leftArr.push_back(temp);
		return ret;
	}
	if (memory[arrSize] != -1)
		return memory[arrSize];

	int temp = leftArr.back();
	leftArr.pop_back();
	ret = max((1 + longestArr(temp, leftArr)), longestArr(num, leftArr));
	leftArr.push_back(temp);
	memory[arrSize] = ret;
	//	cout << arrSize << " " << ret << "\n";
	return ret;

}




int main() {
	setMemory();
	int numArr[1004];
	vector<int> reverseArr;
	for (int i = 0; i < 1004; i++) {
		numArr[i] = 0;
	}
	int arrSize = 0;
	cin >> arrSize;
	for (int i = 0; i < arrSize; i++)
		cin >> numArr[i];
	for (int i = arrSize - 1; i >= 0; i--) {
		reverseArr.push_back(numArr[i]);
	}
	cout << longestArr(0, reverseArr);


	return 0;
}
