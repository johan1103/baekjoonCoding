#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;



int main() {
    int num = 0;
    cin >> num;
    while (num != 1) {
        for (int i = 2; i <= num; i++) {
            if (num % i == 0) {
                cout << i << "\n";
                num /= i;
                break;
            }
        }
    }

    return 0;
}
