#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, u, v, c;

	cin >> n;
	vector<int> ans;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			ans.push_back(i);
			n /= i;
			i = i - 1;
		}
	}
	for (auto i : ans)
		cout << i << '\n';

}