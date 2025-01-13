#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x + 1; j <= y; j++)
			arr[j]++;
	}

	int res = 0;
	for (int i = 1; i <= 100; i++) {
		if (arr[i]) {
			if (arr[i] == 1) res += a;
			else if (arr[i] == 2) res += (2 * b);
			else if (arr[i] == 3) res += (3 * c);
		}
	}
	cout << res;
	
}