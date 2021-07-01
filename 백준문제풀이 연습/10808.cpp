#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;


int main() {
	int alphabet[26] = { 0, };
	string sentence = "";
	cin >> sentence;

	for (int i = 0; i < sentence.size(); i++) {
		alphabet[int(sentence[i]) - 97] += 1;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";

	return 0;
}
