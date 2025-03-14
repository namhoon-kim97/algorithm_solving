#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	vector<pair<int, int>> pools;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pools.push_back({ a,b });
	}
	sort(pools.begin(), pools.end());

	int cnt = 0;
	int st = 0;
	
	for (auto cur : pools) {
		if (st < cur.first) {
			st = cur.first;
		}
		while (st < cur.second) {
			st += l;
			cnt++;
		}
	}
	cout << cnt;	
}