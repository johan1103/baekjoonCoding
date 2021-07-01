#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, string> firstStudent, pair<int, string> secondStudent) {
	if (firstStudent.first < secondStudent.first)
		return true;
	else
		return false;
}


int main() {
	int studentSize = 0;
	cin >> studentSize;
	vector<pair<int, string>> student(studentSize);
	for (int i = 0; i < studentSize; i++) {
		cin >> student[i].first >> student[i].second;
	}


	stable_sort(student.begin(), student.end(), compare);
	for (int i = 0; i < studentSize; i++) {
		cout << student[i].first << " " << student[i].second << "\n";
	}


	return 0;
}
