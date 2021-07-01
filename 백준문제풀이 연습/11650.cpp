#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else if (a.first < b.first)
		return true;
	else
		return false;
}

int main() {
	int t = 0;
	cin >> t;
	vector<pair<int, int>> arr(t);

	for (int i = 0; i < t; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < t; i++)
		cout << arr[i].first << " " << arr[i].second << "\n";

	return 0;
}
