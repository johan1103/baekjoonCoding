#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
using namespace std;

/*
�ƽ�Ű �ڵ�  ����: 32 a: 97 A: 65 0: 48
*/


int main() {
    vector<string> sen;
    string temp;
    cin >> temp;
    int length = temp.length();
    for (int i = 0; i < temp.size(); i++) {
        sen.push_back(temp.substr(i, length));
    }
    sort(sen.begin(), sen.end());
    for (int i = 0; i < sen.size(); i++) {
        cout << sen[i] << "\n";
    }

    return 0;

}
