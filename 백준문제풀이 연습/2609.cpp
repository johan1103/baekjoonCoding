#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int uclid(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main() {
    int a = 0;
    int b = 0;
    cin >> a >> b;
    if (a < b) {
        int r = a;
        a = b;
        b = r;
    }
    int gcd = uclid(a, b);
    cout << gcd;
    cout << "\n" << (a * b) / gcd;


    return 0;

}
