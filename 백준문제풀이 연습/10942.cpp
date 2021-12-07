#include<iostream>
#include<vector>
using namespace std;

int palindrome[2004][2004];
vector<int> num;

int palindromeDp(int start_index,int end_index) {
	if (palindrome[start_index][end_index] != -1)
		return palindrome[start_index][end_index];
	if (end_index <= start_index) {
		palindrome[start_index][end_index] = 1;
		return 1;
	}
	if (num[start_index] == num[end_index]) {
		if (palindromeDp(start_index + 1, end_index - 1)) {
			palindrome[start_index][end_index] = 1;
			return 1;
		}
		else {
			palindrome[start_index][end_index] = 0;
			return 0;
		}
	}
	else {
		palindrome[start_index][end_index] = 0;
		return 0;
	}
//	cout << start_index << " " << end_index << " ";
//	cout << "출력불가\n";
	return 0;
}
void setMemory() {
	for (int i = 0; i < 2004; i++) {
		for (int j = 0; j < 2004; j++)
			palindrome[j][i] = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	setMemory();
	int N = 0;
	cin >> N;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			palindromeDp(i, j);
		}
	}
	int M = 0;
	cin >> M;
	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		cout << palindrome[start - 1][end - 1] << "\n";
	}
	return 0;
}