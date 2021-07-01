#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 1004

using namespace std;
vector<int> posNum;
vector<int> negNum;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool compare(int a, int b) {
    return
        a > b;
}
void numCombine() {
    int result = 0;
    int temp = 0;
    // 정렬
    sort(negNum.begin(), negNum.end(), compare);
    sort(posNum.begin(), posNum.end());
    // 음수 양수 각각 같은 알고리즘으로 해결
    // 두개씩 뽑고 곱해주기, 하나 남으면 result에 더해주고 끝내기
    while (!negNum.empty()) {
        temp = negNum.back();
        negNum.pop_back();
        if (negNum.empty()) {
            result += temp;
        }
        else {
            temp *= negNum.back();
            negNum.pop_back();
            result += temp;
        }
    }
    while (!posNum.empty()) {
        temp = posNum.back();
        posNum.pop_back();
        if (posNum.empty()) {
            result += temp;
        }
        else {
            if (posNum.back() == 1) {
                result += temp + 1;
                posNum.pop_back();
            }
            else {
                temp *= posNum.back();
                posNum.pop_back();
                result += temp;
            }
        }
    }
    cout << result;
}

int main() {
    init();
    int n = 0;
    int num = 0;
    cin >> n;
    // 음수,양수 다른 벡터에 저장(0은 음수에 넣어야함, 그래야 하나남은 음수를 없앨수있음,양수도 피해안보고)
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num <= 0)
            negNum.push_back(num);
        else
            posNum.push_back(num);
    }
    numCombine();
    return 0;
}