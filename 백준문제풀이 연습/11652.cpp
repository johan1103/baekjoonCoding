#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	vector<long long int> arr(t + 1);
	for (int i = 0; i < t; i++)
		cin >> arr[i];
	arr[t] = 4611686018427387905;
	sort(arr.begin(), arr.end());
	int maxTime = 0;
	long long int temp = arr[0];
	int result = 0;
	long long int resultValue = 0;
	for (int i = 0; i <= t; i++) {
		if (temp == arr[i])
			maxTime += 1;
		else {
			if (maxTime > result) {
				result = maxTime;
				resultValue = temp;
			}
			maxTime = 1;
			temp = arr[i];
		}
	}
	cout << resultValue;
	return 0;
}
