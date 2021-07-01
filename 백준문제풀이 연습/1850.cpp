#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main() {

    long long a = 0, b = 0;
    cin >> a >> b;
    if (a < b) {
        long long r = a;
        a = b;
        b = r;
    }
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    for (int i = 0; i < a; i++) {
        cout << "1";
    }

    return 0;

}
