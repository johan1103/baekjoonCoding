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
    // ����
    sort(negNum.begin(), negNum.end(), compare);
    sort(posNum.begin(), posNum.end());
    // ���� ��� ���� ���� �˰������� �ذ�
    // �ΰ��� �̰� �����ֱ�, �ϳ� ������ result�� �����ְ� ������
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
    // ����,��� �ٸ� ���Ϳ� ����(0�� ������ �־����, �׷��� �ϳ����� ������ ���ټ�����,����� ���ؾȺ���)
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