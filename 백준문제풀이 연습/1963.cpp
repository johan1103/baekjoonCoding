#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 10004

using namespace std;
int even[MAX_SIZE];
int visit[MAX_SIZE];
deque<int> list;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void evenCheck() {
    even[2] = 0;
    for (int i = 2; i < 10000; i++) {
        if (even[i] == 0) {
            for (int j = i * 2; j < 10000; j += i) {
                even[j] = 1;
            }
        }
    }
}
int changeNum(vector<int> arr) {
    int result = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        result *= 10;
        result += arr[i];
    }
    return result;
    return 0;
}
int pushNum(int num) {
    vector<int> arr;
    int originalNum = num;
    while (num != 0) {
        arr.push_back(num % 10);
        num /= 10;
    }
    num = originalNum;
    int temp = 0;
    int number = 0;
    for (int i = 0; i < 4; i++) {
        temp = arr[i];
        for (int j = 0; j <= 9; j++) {
            if (j == temp)
                continue;
            arr[i] = j;
            number = changeNum(arr);
            if (even[number] == 0 && number >= 1000 && visit[number] == 0) {
                visit[number] = visit[num] + 1;
                list.push_back(number);
            }
        }
        arr[i] = temp;
    }
    return 0;
}
void bfs(int start, int destination) {
    int result = 0;
    list.push_back(start);
    visit[start] = 0;
    while (!list.empty()) {
        start = list.front();
        list.pop_front();
        if (destination == start) {
            result = visit[start];
            cout << result << "\n";
            return;
        }
        pushNum(start);
    }
    if (result == 0) {
        cout << "Impossible\n";
        return;
    }
}
int main() {
    init();
    evenCheck();

    int time = 0;
    cin >> time;
    for (int i = 0; i < time; i++) {
        int start = 0, destination = 0;
        cin >> start >> destination;
        bfs(start, destination);
        list.clear();
        memset(visit, 0, sizeof(visit));
    }
    //에라토네스체 테스트
    /*
    for (int i = 2; i < 10000; i++) {
        if (even[i] == 0)
            cout << i << " ";
    }
    */
    // 숫자 한자리씩 바꿔서 큐에 추가하는 테스트
    /*
    pushNum(3733);
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    */
    return 0;
}