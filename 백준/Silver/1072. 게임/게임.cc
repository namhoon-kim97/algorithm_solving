#include <bits/stdc++.h>
using namespace std;
long long x, y;
int z;

bool solution(int n) {
	return ((y + n) * 100) / (x + n) > (y * 100) / x;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);


	cin >> x >> y;
	z = (y * 100) / x;
	if (z >= 99) {
		cout << -1;
		return 0;
	}

	long long ans = 0;
	long long st = 1;
	long long en = 1e9;
	while (st <= en) {
		long long mid = (st + en) / 2;
		if (solution(mid)) {
			ans = mid;
			en = mid-1;
		}
		else st = mid + 1;
	}
	cout << ans;
}