#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 100004

using namespace std;
int n = 0;
int arr[MAX_SIZE];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    init();
    cin >> n;
    int result = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    do {
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += abs(arr[i] - arr[i - 1]);
        }
        result = max(sum, result);
    } while (next_permutation(arr, arr + n));
    cout << result;
    return 0;
}