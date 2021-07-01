#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;



int main() {
    int zeroDeny = 0;
    int num = 0;
    int result = 1;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        result *= i;
        result %= 10000;
        while (result % 10 == 0) {
            zeroDeny += 1;
            result /= 10;
        }
    }
    cout << zeroDeny;
    return 0;
}
