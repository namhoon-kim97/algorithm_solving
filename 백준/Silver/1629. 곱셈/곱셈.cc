#include <bits/stdc++.h>

using namespace std;

long long myPow(int a, int b, int c) {
	if (b == 0) return 1;
	if (b == 1) return a % c;
	
	long long half = myPow(a, b / 2, c);
	half = (half * half) % c;
	if (b % 2 != 0) {
		half = (half * a) % c;
	}
	return half;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;

	cout << myPow(a, b, c);
}