#include <bits/stdc++.h>
using namespace std;
int arr[1000001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> res = {arr[0]};
    for (int i = 1; i < n; i++) {
        if (res[res.size() - 1] < arr[i]) {
            res.push_back(arr[i]);
        }
        else {
            int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[idx] = arr[i];
        }
    }
    cout << res.size();
    /*for (int i = 0; i < n; i++)
        cout << d[i] << ' ';*/
}