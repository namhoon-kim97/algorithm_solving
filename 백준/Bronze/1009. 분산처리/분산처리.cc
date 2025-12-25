#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long a, b;
        cin >> a >> b;

        int last = a % 10;

        if (last == 0) {
            cout << 10 << '\n';
        }
        else if (last == 1 || last == 5 || last == 6) {
            cout << last << '\n';
        }
        else if (last == 4) {
            cout << (b % 2 == 1 ? 4 : 6) << '\n';
        }
        else if (last == 9) {
            cout << (b % 2 == 1 ? 9 : 1) << '\n';
        }
        else {
            int cycle[4];
            if (last == 2) { int tmp[4] = { 2,4,8,6 }; copy(tmp, tmp + 4, cycle); }
            if (last == 3) { int tmp[4] = { 3,9,7,1 }; copy(tmp, tmp + 4, cycle); }
            if (last == 7) { int tmp[4] = { 7,9,3,1 }; copy(tmp, tmp + 4, cycle); }
            if (last == 8) { int tmp[4] = { 8,4,2,6 }; copy(tmp, tmp + 4, cycle); }

            int idx = (b - 1) % 4;
            cout << cycle[idx] << '\n';
        }
    }
    return 0;
}
