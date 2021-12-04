#include<iostream>
#include<vector>
#define MAX 1004
using namespace std;

vector<int> num_list;
int dp_front[MAX];
int dp_back[MAX];


int biotonicArray() {
	int result = 0;
	
	for (int i = 0; i < num_list.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (num_list[j] < num_list[i])
				dp_front[i] = max(dp_front[i], dp_front[j] + 1);
		}
	}
	for (int i = num_list.size()-1; i >= 0; i--) {
		for (int j = num_list.size() - 1; j > i; j--) {
			if (num_list[j] < num_list[i])
				dp_back[i] = max(dp_back[i], dp_back[j] + 1);
		}
		result = max(result, dp_front[i] + dp_back[i] - 1);
	}
	return result;
}

int main() {
	for (int i = 0; i < MAX; i++) {
		dp_front[i] = 1;
		dp_back[i] = 1;
	}
	int N;
	cin >> N;
//	srand(time(NULL));
//	int s_time = clock();
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		num_list.push_back(tmp);
//		num_list.push_back(rand() % 1000);
	}
//	int e_time = clock();
	cout << biotonicArray();
//	cout<< "\n" << e_time - s_time;
	/*
	for (int i = 0; i < N; i++) {
		cout << dp_front[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << dp_back[i] << " ";
	}
	*/
	return 0;
}