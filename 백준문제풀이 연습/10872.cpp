#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;



int main() {
    int fac = 0;
    cin >> fac;
    int result = 1;
    for (int i = 1; i <= fac; i++) {
        result *= i;
    }
    cout << result;
    return 0;
}
