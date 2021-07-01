#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 100000

using namespace std;
int number[MAX_SIZE];
string num;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool check() {
    bool zero = 0;
    int result = 0;
    for (int i = 0; i < num.size(); i++) {
        result += number[i];
        if (number[i] == 0)
            zero = 1;
    }
    if (zero == 1 && result % 3 == 0)
        return true;
    else
        return false;
}
void crazy30() {
    if (check() == false) {
        cout << -1;
        return;
    }
    else {
        sort(number, number + num.size());
        for (int i = num.size() - 1; i >= 0; i--)
            cout << number[i];
    }
    return;
}

int main() {
    init();
    cin >> num;
    for (int i = 0; i < num.size(); i++) {
        number[i] = num[i] - '0';
    }
    crazy30();
    return 0;
}