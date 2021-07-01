#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
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
    int num = -1;
    bool wrong = 0;
    while(num!=0){
        cin >> num;
        for (int i = 2; i <= num / 2; i++) {
            if (dec[i] == 1)
                continue;
            else if (dec[i] == 0 && dec[num - i] == 0) {
                cout << num << " = " << i << " + " << num - i << "\n";
                wrong = 1;
                break;
            }
        }
        if (wrong == 0)
            cout << "Goldbach's conjecture is wrong." << "\n";
    }
    
    return 0;
}
