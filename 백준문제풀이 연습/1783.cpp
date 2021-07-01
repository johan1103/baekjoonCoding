#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

#define MAX_SIZE 100000

using namespace std;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    init();
    int n = 0, m = 0;
    cin >> n >> m;
    if (n == 1)
        cout << 1 << endl;
    else if (n == 2)
        cout << min(4, (m + 1) / 2) << "\n";
    else if (n >= 3) {
        if (m <= 6)
            cout << min(4, m) << "\n";
        else
            cout << m - 2 << "\n";
    }
    return 0;
}