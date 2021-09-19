#include<iostream>
#include<vector>
#define INF 1e9

using namespace std;

int N;

int down_dp() {
	int min_result = INF;
	int max_result = 0;
	int a, b, c;
	int tmp1, tmp2, tmp3;
	int memory[3][2] = { {0,0},{0,0},{0,0} };
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		tmp1 = memory[0][0];
		tmp2 = memory[1][0];
		tmp3 = memory[2][0];
		memory[0][0] = max(a + tmp1, a + tmp2);
		memory[1][0] = max(b + tmp2, max(b + tmp1, b + tmp3));
		memory[2][0] = max(c + tmp2, c + tmp3);

		tmp1 = memory[0][1];
		tmp2 = memory[1][1];
		tmp3 = memory[2][1];
		memory[0][1] = min(a + tmp1, a + tmp2);
		memory[1][1] = min(b + tmp2, min(b + tmp1, b + tmp3));
		memory[2][1] = min(c + tmp2, c + tmp3);
	}
	for (int i = 0; i < 3; i++) {
		max_result = max(max_result, memory[i][0]);
		min_result = min(min_result, memory[i][1]);
	}
	cout << max_result << " " << min_result;
	return 0;
}

int main() {
	cin >> N;
	down_dp();
	return 0;
}
