#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int t = 0;
    cin >> t;
    int arr[104];
    int n = 0;
    for (int i = 0; i < t; i++) {
        long long sum = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < j; p++) {
                sum += gcd(arr[j], arr[p]);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
