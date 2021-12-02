#include<iostream>
#include<vector>
using namespace std;

vector<int> wine_list;
int memory[10004][4];

int wineDp(int now_wine,int drink_time) {
	if (now_wine >= wine_list.size())
		return 0;
	if (memory[now_wine][drink_time] != -1)
		return memory[now_wine][drink_time];
	int result = 0;
	if (drink_time == 2) {
		result = wineDp(now_wine + 1, 0);
		memory[now_wine][drink_time] = result;
//		cout << result << "  || " << now_wine << "\n";
		return result;
	}
	else {
		result = wineDp(now_wine + 1, 0);
		result = max(result, wineDp(now_wine + 1, drink_time + 1) + wine_list[now_wine]);
		memory[now_wine][drink_time] = result;
//		cout << result << "  || " << now_wine << "\n";
		return result;
	}
	return 0;
}

int main() {
	for (int i = 0; i < 10004; i++) {
		for (int j = 0; j < 4; j++)
			memory[i][j] = -1;
	}
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		wine_list.push_back(tmp);
	}
	cout << wineDp(0, 0);
	return 0;
}