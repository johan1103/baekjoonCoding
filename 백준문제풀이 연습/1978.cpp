#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


int main() {
    int n = 0;
    int dec[1004];
    for (int i = 0; i < 1004; i++)
        dec[i] = 0;
    dec[1] = 1;
    for (int i = 2; i < 1004; i++) {
        if (dec[i] == 0) {
            for (int j = i * 2; j < 1004; j += i) {
                if (dec[j] == 1)
                    continue;
                dec[j] = 1;
            }
        }
    }
    int que = 0;
    int t = 0;
    int result = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> que;
        if (dec[que] == 0)
            result += 1;
    }
    cout << result;

    return 0;
}
