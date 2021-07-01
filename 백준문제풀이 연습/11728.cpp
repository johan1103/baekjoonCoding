#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 1000004
#define MAX_NUM 1000000004

using namespace std;
deque<int> arrA;
deque<int> arrB;
vector<int> combind;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void combineArr() {
    while (!arrA.empty() && !arrB.empty()) {
        if (arrA.front() <= arrB.front()) {
            combind.push_back(arrA.front());
            arrA.pop_front();
        }
        else {
            combind.push_back(arrB.front());
            arrB.pop_front();
        }
    }
}

int main() {
    init();
    int N = 0, M = 0;
    int temp = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arrA.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        arrB.push_back(temp);
    }
    arrA.push_back(MAX_NUM);
    arrB.push_back(MAX_NUM);
    combineArr();
    for (int i = 0; i < combind.size() - 1; i++)
        cout << combind[i] << " ";

    return 0;
}