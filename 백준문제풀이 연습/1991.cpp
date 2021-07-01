#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>

#define MAX_SIZE 104

using namespace std;

struct node {
    char left;
    char right;
};
node arr[27];
void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void preOrder(char start) {
    if (start == '.')
        return;
    cout << start;
    preOrder(arr[start].left);
    preOrder(arr[start].right);
}
void inOrder(char start) {
    if (start == '.')
        return;
    inOrder(arr[start].left);
    cout << start;
    inOrder(arr[start].right);
}
void postOrder(char start) {
    if (start == '.')
        return;
    postOrder(arr[start].left);
    postOrder(arr[start].right);
    cout << start;
}



int main() {
    init();
    int N = 0;
    char a, b, c;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";
    return 0;
}
