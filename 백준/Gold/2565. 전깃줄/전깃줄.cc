#include <bits/stdc++.h>
using namespace std;
int arr[501];
int d[501];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
        m = max(m, a);
    }

    for (int i = 1; i <= m; i++) {
        if (arr[i] != 0) {
            d[i] = 1;
            for (int j = i - 1; j >= 1; j--) {
                if (arr[j] < arr[i] && arr[j] != 0)
                    d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    cout << n - (*max_element(d + 1, d + m + 1));
}