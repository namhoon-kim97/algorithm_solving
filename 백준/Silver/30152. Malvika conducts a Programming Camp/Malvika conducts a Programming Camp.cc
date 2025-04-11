#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n <= 2)
            cout << (n - 1) * m << '\n';
        else
            cout << (n - 1) + 2 * (m - 1) << '\n';
    }
}
