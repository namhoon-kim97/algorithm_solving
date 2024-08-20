#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> um;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        um[temp] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        if (um[temp] == 1)
            cnt++;
    }
    cout << cnt;
}
