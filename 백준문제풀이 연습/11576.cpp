#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


int main() {
    int A = 0, B = 0;
    cin >> A >> B;
    int numSize = 0;
    long long ten = 0;
    int temp = 0;
    vector<int> numB;
    cin >> numSize;
    for (int i = 0; i < numSize; i++) {
        ten *= A;
        cin >> temp;
        ten += temp;
    }
    while (ten != 0) {
        numB.push_back(ten % B);
        ten /= B;
    }
    for (int i = numB.size() - 1; i >= 0; i--)
        cout << numB[i] << " ";

    return 0;
}
