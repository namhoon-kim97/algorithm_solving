#include <bits/stdc++.h>

using namespace std;
int arr[1000001];


bool is_exist(int x, int n) {
    int st = 0;
    int en = n - 1;

    while (st <= en) {
        int mid = (st + en) / 2;
        if (arr[mid] < x)
            st = mid + 1;
        else if (arr[mid] > x)
            en = mid - 1;
        else
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            if (is_exist(a,n))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}
