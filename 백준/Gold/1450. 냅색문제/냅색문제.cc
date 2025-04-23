#include <bits/stdc++.h>
using namespace std;

int n, c;
int arr[31];
vector<int> v1, v2;

void go(int st, int en, vector<int>& v, int sum) {
    if (sum > c) return;
    if (st > en) {
        v.push_back(sum);
        return;
    }
    go(st + 1, en, v, sum + arr[st]);
    go(st + 1, en, v, sum);
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    go(0, n / 2 - 1, v1, 0);
    go(n / 2, n - 1, v2, 0);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ret = 0;
    for (int a : v1) {
        if (c - a >= 0)
            ret += ((int)(upper_bound(v2.begin(), v2.end(), c - a) - v2.begin()));
    }
    cout << ret;

}