#include <bits/stdc++.h>

using namespace std;

long long arr[10001];
int n,m;

bool solve(long long mid) {
    long long temp = m;
    for (int i = 0; i < n; i++) {
        if (mid < arr[i])
            temp -= mid;
        else
            temp -= arr[i];
    }
    if (temp >= 0)
        return true;
    else 
        return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long en = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        en = max(arr[i], en);
    }

    cin >> m;

 
    long long st = 1;
    while (st < en) {
        long long mid = (st + en + 1)/ 2;
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}