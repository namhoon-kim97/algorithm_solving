#include <bits/stdc++.h>
using namespace std;

int memory[101];
int deactive[101];
int dp[10001]; // dp[cost] = cost이하로 썼을 때 확보 가능한 최대 메모리
int n, m, sum;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> memory[i];
    for (int i = 0; i < n; i++) {
        cin >> deactive[i];
        sum += deactive[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= deactive[i]; j--){
            dp[j] = max(dp[j], dp[j - deactive[i]] + memory[i]);
        }
    }
    for (int i = 0; i <= sum; i++) {
        if (dp[i] >= m) {
            cout << i << "\n"; // 최소 비용 출력
            break;
        }
    }
}