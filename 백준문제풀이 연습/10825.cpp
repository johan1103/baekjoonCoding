#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct student {
	string name;
	int kor = 0, eng = 0, math = 0;
};


bool compare(student a, student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng)
			if (a.math == b.math)
				return a.name < b.name;
			else
				return a.math > b.math;
		else
			return a.eng < b.eng;
	}
	else
		return a.kor > b.kor;
}


int main() {
	int studentSize = 0;
	cin >> studentSize;
	vector<student> studentList(studentSize);
	for (int i = 0; i < studentSize; i++) {
		cin >> studentList[i].name >> studentList[i].kor >> studentList[i].eng >> studentList[i].math;
	}
	sort(studentList.begin(), studentList.end(), compare);
	for (int i = 0; i < studentSize; i++) {
		cout << studentList[i].name << "\n";
	}

	return 0;
}
