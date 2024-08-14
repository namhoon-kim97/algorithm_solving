#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int d[100001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    d[0][0] = arr[0];
    d[0][1] = arr[0];

    int ans = arr[0];
    for (int i = 1; i < n; i++) {
        d[i][0] = max(d[i - 1][0] + arr[i], arr[i]);
        d[i][1] = max(d[i - 1][0], d[i - 1][1] + arr[i]);
        ans = max(ans,max(d[i][0], d[i][1]));
    }

    cout << ans;
}
