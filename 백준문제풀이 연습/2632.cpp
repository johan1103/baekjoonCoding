#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

using namespace std;

#define MAX_SIZE 1000004
int pizzaPiece[2][MAX_SIZE];
int num[2][MAX_SIZE];
vector<int> pizzaCase[2];
int n[2];
int m = 0;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
// 피자 시작지점에 따른 부분합 전부 계산(한판 전부인경우만 제외
void pizza(int now, int ab) {
    int result = 0;
    for (int i = 0; i <= n[ab] - 2; i++) {
        result += pizzaPiece[ab][(now + i) % n[ab]];
        if (num[ab][result] != 0) {
            num[ab][result] += 1;
            continue;
        }
        else {
            pizzaCase[ab].push_back(result);
            num[ab][result] += 1;
        }
    }
}
// 시작지점 전부 다르게 해서 부분합 총합
void pizzaCal(int ab) {
    for (int i = 0; i < n[ab]; i++)
        pizza(i, ab);
    int temp = 0;
    for (int i = 0; i < n[ab]; i++) {
        temp += pizzaPiece[ab][i];
    }
    num[ab][temp] += 1;
    pizzaCase[ab].push_back(temp);
    return;
}

int main() {
    init();
    int result = 0;
    cin >> m;
    cin >> n[0] >> n[1];
    //피자 입력
    for (int i = 0; i < n[0]; i++) {
        cin >> pizzaPiece[0][i];
    }
    for (int i = 0; i < n[1]; i++) {
        cin >> pizzaPiece[1][i];
    }
    //피자 계산
    pizzaCal(0);
    pizzaCal(1);
    for (int i = 0; i < pizzaCase[0].size(); i++) {
        int temp = m - pizzaCase[0][i];
        if (temp == 0) {
            result += num[0][pizzaCase[0][i]];
            continue;
        }
        if (num[1][temp] != 0) {
            result += num[0][pizzaCase[0][i]] * num[1][temp];
        }
        else
            continue;
    }
    for (int i = 0; i < pizzaCase[1].size(); i++) {
        int temp = m - pizzaCase[1][i];
        if (temp == 0)
            result += num[1][pizzaCase[1][i]];
        else
            continue;
    }
    cout << result;
    /*
    for (int i = 0; i < pizzaCase[0].size(); i++) {
        cout << pizzaCase[0][i] << " " << num[0][pizzaCase[0][i]] << "\n";
    }
    cout << "------------------------------------------------\n";
    for (int i = 0; i < pizzaCase[1].size(); i++) {
        cout << pizzaCase[1][i] << " " << num[1][pizzaCase[1][i]] << "\n";
    }
    */
    return 0;
}