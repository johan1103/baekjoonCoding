#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
using namespace std;

/*
아스키 코드  공백: 32 a: 97 A: 65 0: 48
*/

void menu(vector<char>& l, vector<char>& r, char order) {
    if (order == 'L') {
        if (l.size() == 0)
            return;
        char code = l.back();
        l.pop_back();
        r.push_back(code);
        return;
    }
    else if (order == 'D') {
        if (r.size() == 0)
            return;
        char code = r.back();
        r.pop_back();
        l.push_back(code);
        return;
    }
    else if (order == 'B') {
        if (l.size() == 0)
            return;
        l.pop_back();
        return;
    }
    else if (order == 'P') {
        char code;
        cin >> code;
        l.push_back(code);
        return;
    }
}


int main() {
    string sen;
    vector<char> leftBody;
    vector<char> rightBody;
    char order;
    int time = 0;
    cin >> sen >> time;
    for (int i = 0; i < sen.size(); i++)
        leftBody.push_back(sen[i]);
    for (int i = 0; i < time; i++) {
        cin >> order;
        menu(leftBody, rightBody, order);
    }
    for (int i = 0; i < leftBody.size(); i++) {
        cout << leftBody[i];
    }
    while (rightBody.size() > 0) {
        cout << rightBody.back();
        rightBody.pop_back();
    }

    return 0;

}
