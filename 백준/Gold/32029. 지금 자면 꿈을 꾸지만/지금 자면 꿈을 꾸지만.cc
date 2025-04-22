#include <bits/stdc++.h>
using namespace std;
int arr[101];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int res = 0;
    
    for (int i = 0; i < a; i++) { // 수면 시간 선택
        int tempA = a - i;
        int sleep = b * i;

        // k까지 안자고 진행 이후 수면
        for (int k = 1; k <= n; k++) {
            int time = 0, cnt = 0;
            for (int j = 1; j < k; j++) {
                if (time + a <= arr[j]) {
                    time += a;
                    cnt++;
                }
            }

            time += sleep;

            for (int j = k; j <= n; j++) {
                if (time + tempA <= arr[j]) {
                    time += tempA;
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
    }
    cout << res;
}
