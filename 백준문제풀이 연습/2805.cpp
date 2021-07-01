#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 1000004
long long treeSize[MAX_SIZE];
long long need = 0;
int n = 0;

using namespace std;

bool possible(long long height) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (treeSize[i] < height)
            continue;
        else {
            cnt += treeSize[i] - height;
        }
    }
    if (cnt >= need)
        return true;
    else
        return false;
}

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}


int main() {
    init();
    cin >> n >> need;
    long long high = 0;
    long long low = 1;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        cin >> treeSize[i];
        high = max(high, treeSize[i]);
    }
    while (high >= low) {
        long long mid = (high + low) / 2;
        if (possible(mid)) {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << result << "\n";

    return 0;
}
