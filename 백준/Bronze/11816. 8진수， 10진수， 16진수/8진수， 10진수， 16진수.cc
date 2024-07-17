#include <bits/stdc++.h>

using namespace std;

int hexToDec(string x) {
    int ret = 0;
    int base = 1; // 16^0

    for (int i = x.size() - 1; i >= 2; i--) {
        if (x[i] >= '0' && x[i] <= '9') {
            ret += (x[i] - '0') * base;
        }
        else if (x[i] >= 'a' && x[i] <= 'f') {
            ret += (x[i] - 'a' + 10) * base;
        }
        else if (x[i] >= 'A' && x[i] <= 'F') {
            ret += (x[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    return ret;
}

int octToDec(string x) {
    int ret = 0;
    int base = 1;

    for (int i = x.size() - 1; i >= 1; i--) {
        ret += (x[i] - '0') * base;
        base *= 8;
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string x;
	cin >> x;

	if (x[0] == '0' && x[1] == 'x')
		cout << hexToDec(x);
	else if (x[0] == '0')
		cout << octToDec(x);
	else
		cout << x;
}