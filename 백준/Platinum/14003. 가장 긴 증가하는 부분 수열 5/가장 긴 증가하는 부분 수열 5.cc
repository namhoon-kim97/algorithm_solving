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
    vector<int> idx = {0};
    for (int i = 1; i < n; i++) {
        if (res[res.size() - 1] < arr[i]) {
            res.push_back(arr[i]);
            idx.push_back(res.size() - 1);
        }
        else {
            int j = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[j] = arr[i];
            idx.push_back(j);
        }
    }
   
    cout << res.size() << '\n';
    int j = res.size() - 1;
    vector<int> ret;
    for (int i = idx.size() - 1; i >=0; i--) {
        if (idx[i] == j) {
            //cout << arr[i] << ' ';
            ret.push_back(arr[i]);
            j--;
        }
    }
    for (int i = ret.size() - 1; i >= 0; i--)
        cout << ret[i] << ' ';
    /*for (int i = 0; i < n; i++)
        cout << d[i] << ' ';*/
}