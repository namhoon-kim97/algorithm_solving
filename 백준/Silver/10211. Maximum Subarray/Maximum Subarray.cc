#include <bits/stdc++.h>

using namespace std;
int arr[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int cur = arr[0];
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            cur = max(cur + arr[i], arr[i]);
            ans = max(cur, ans);
        }
        cout << ans << '\n';
    }

}
