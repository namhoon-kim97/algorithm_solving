#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int K;
    cin >> K;
    for (int k = 1; k <= K; k++) {
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> vo, vx;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] == 'O') vo.push_back(i);
            else vx.push_back(i);
        }
        int ans = 0;
        while (s1.compare(s2) != 0) {
            ans++;
            int oi = 0, xi = 0;
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] == 'O') {
                    if (i < vo[oi] && s1[i] != s1[i + 1]) {
                        s1[i] = 'X';
                        s1[i + 1] = 'O';
                        i++;
                        xi++;
                    }
                    oi++;
                }
                else {
                    if (i < vx[xi] && s1[i] != s1[i + 1]) {
                        s1[i] = 'O';
                        s1[i + 1] = 'X';
                        i++;
                        oi++;
                    }
                    xi++;
                }
            }
        }
        cout << "Data Set " << k << ":\n" << ans << "\n\n";
    }
}