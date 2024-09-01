#include <bits/stdc++.h>

using namespace std;

int d[100001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    // d[i][0]: i번째 열까지 배치할 때, i 번째 열에 배치 X
    // d[i][1]: i번째 열까지 배치할 때, i 번째 열에 왼쪽 배치 O
    // d[i][2]: i번째 열까지 배치할 때, i 번째 열에 오른쪽 배치 O
    
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
        d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;
        d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 9901;
    }

    cout << (d[n][0] + d[n][1] + d[n][2]) % 9901;
}