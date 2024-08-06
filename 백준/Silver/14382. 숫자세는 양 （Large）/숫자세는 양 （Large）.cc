#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int cnt = 1;
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 0) {
            cout << "Case #" << cnt << ": " << "INSOMNIA" << '\n';
            cnt++;
            continue;
        }

        set<char> digits;
        int multi = 0;
        int cur;

        while (digits.size() < 10) {
            multi++;
            cur = multi * n;
            string num_str = to_string(cur);
            for (char a : num_str)
                digits.insert(a);
        }
        
        cout << "Case #" << cnt << ": " << cur << '\n';
        cnt++;
    }
}