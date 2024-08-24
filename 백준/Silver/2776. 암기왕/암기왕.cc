#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int arr[1000001];


bool is_exist(int x, int n) {
    int st = 0;
    int en = n;

    while (st < en) {
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
        unordered_map<int, int> um;
        int n,m;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            um[temp] = 1;
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            if (um[a] == 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        //fill(arr, arr + n, 0);
    }
}
