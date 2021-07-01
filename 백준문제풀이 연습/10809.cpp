#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;


int main() {
	int alphabet[26];
	for (int i = 0; i < 26; i++)
		alphabet[i] = -1;
	string sentence = "";
	cin >> sentence;
	int locate = 0;
	for (int i = 0; i < sentence.size(); i++) {
		locate = int(sentence[i]) - 97;
		if (alphabet[locate] != -1)
			continue;
		alphabet[locate] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";
	return 0;
}
