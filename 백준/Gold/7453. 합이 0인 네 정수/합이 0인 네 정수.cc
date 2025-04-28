#include <bits/stdc++.h>
using namespace std;
int a[4001];
int b[4001];
int c[4001];
int d[4001];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> ab;
    vector<int> cd;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cd.push_back(c[i] + d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    int lo = 0;
    int hi = cd.size() - 1;
    long long res = 0;
    while (lo < ab.size() && hi >= 0) {
        int sum = ab[lo] + cd[hi];
        if (sum == 0) {
            long long c1 = upper_bound(ab.begin(), ab.end(), ab[lo]) - lower_bound(ab.begin(), ab.end(), ab[lo]);
            long long c2 = upper_bound(cd.begin(), cd.end(), cd[hi]) - lower_bound(cd.begin(), cd.end(), cd[hi]);
            res += c1 * c2;
            lo += c1;
            hi -= c2;
        }
        else if (sum < 0) lo++;
        else hi--;
    }
    cout << res;
}