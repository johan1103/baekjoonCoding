#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

void menu(string order, queue<int>& arr) {
	int x = 0;
	if (order == "push") {
		cin >> x;
		arr.push(x);
		return;
	}
	else if (order == "pop") {
		if (arr.size() == 0)
			cout << -1 << "\n";
		else {
			cout << arr.front() << "\n";
			arr.pop();
		}
		return;
	}
	else if (order == "size") {
		cout << arr.size() << "\n";
		return;
	}
	else if (order == "empty") {
		if (arr.size() == 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
		return;
	}
	else if (order == "front") {
		if (arr.size() == 0)
			cout << -1 << "\n";
		else
			cout << arr.front() << "\n";
		return;
	}
	else if (order == "back") {
		if (arr.size() == 0)
			cout << -1 << "\n";
		else
			cout << arr.back() << "\n";
		return;
	}
}

int main() {
	queue<int> a;
	int time = 0;
	string order = "";
	cin >> time;
	for (int i = 0; i < time; i++) {
		cin >> order;
		menu(order, a);
	}
	return 0;
}
