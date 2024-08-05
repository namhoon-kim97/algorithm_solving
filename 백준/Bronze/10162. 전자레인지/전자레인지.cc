#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	
	int a = 0;
	int b = 0;
	int c = 0;
	while (t >= 300) {
		t -= 300;
		a++;
	}
	while (t >= 60) {
		t -= 60;
		b++;
	}
	while (t >= 10) {
		t -= 10;
		c++;
	}

	if (t != 0)
		cout << -1;
	else
		cout << a << ' ' << b << ' ' << c;
}