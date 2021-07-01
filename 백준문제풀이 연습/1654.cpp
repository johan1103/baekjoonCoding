#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 100004

using namespace std;

long long len[MAX_SIZE];
int n = 0;
int k = 0;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool possible(long long leng) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += len[i] / leng;
    }
    if (cnt >= k)
        return true;
    else
        return false;
}


int main() {
    init();
    long long high = 0;
    long long low = 1;
    long long result = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> len[i];
        if (len[i] > high)
            high = len[i];
    }
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (possible(mid)) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << result << "\n";

    return 0;
}
