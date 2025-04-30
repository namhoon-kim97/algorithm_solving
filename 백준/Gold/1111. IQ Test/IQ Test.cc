#include <bits/stdc++.h>
using namespace std;
int arr[51];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n < 2) {
        cout << "A"; return 0;
    }

    if (n == 2) {
        if (arr[0] == arr[1])
            cout << arr[0];
        else
            cout << "A";
        return 0;
    }
    // 1a + b = 4;
    // 4a + b = 13;
    // 3a = 9;
    int a, b;
    if (arr[1] - arr[0] == 0) {
        a = 1;
        b = 0;
    }
    else {
        a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
        b = arr[2] - (arr[1] * a);
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] * a + b != arr[i + 1]) {
            cout << "B";
            return 0;
        }
    }

    cout << arr[n - 1] * a + b;
}