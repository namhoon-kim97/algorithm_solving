#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c;

	int x, y, z;
	int ans = 0;
	x = -1;
	y = -1;
	z = -1;
	if (a[0] >= '0' && a[0] <= '9') {
		x = stoi(a);
	}
	if (b[0] >= '0' && b[0] <= '9') {
		y = stoi(b);
	}
	if (c[0] >= '0' && c[0] <= '9') {
		z = stoi(c);
	}
	if (x != -1)
		ans = x + 3;
	if (y != -1)
		ans = y + 2;
	if (z != -1)
		ans = z + 1;
	if (ans % 15 == 0)
		cout << "FizzBuzz";
	else if (ans % 3 == 0)
		cout << "Fizz";
	else if (ans % 5 == 0)
		cout << "Buzz";
	else
		cout << ans;
}