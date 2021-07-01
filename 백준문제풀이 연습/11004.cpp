#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 0;
	int n = 0;
	cin >> t >> n;;
	vector<int> arr(t);
	for (int i = 0; i < t; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	cout << arr[n - 1];

	return 0;
}
