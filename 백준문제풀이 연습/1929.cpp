#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;



int main() {
    int n = 0;
    bool dec[1000004];
    for (int i = 0; i < 1000004; i++)
        dec[i] = 0;
    dec[1] = 1;
    for (int i = 2; i < 1000004; i++) {
        if (dec[i] == 0) {
            for (int j = i * 2; j < 1000004; j += i) {
                if (dec[j] == 1)
                    continue;
                dec[j] = 1;
            }
        }
    }
    int M = 0, N = 0;
    cin >> M >> N;
    for (int i = M; i <= N; i++) {
        if (dec[i] == 0)
            cout << i << "\n";
    }

    return 0;
}
