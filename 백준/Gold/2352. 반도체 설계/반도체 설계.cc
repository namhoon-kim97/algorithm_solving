#include <bits/stdc++.h>
using namespace std;
int arr[40001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<int> res = { arr[1] };
    for (int i = 2; i <= n; i++) {
        if (res[res.size() - 1] < arr[i]) {
            res.push_back(arr[i]);
        }
        else {
            int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[idx] = arr[i];
        }
    }
    cout << res.size();
}