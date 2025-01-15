#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	vector<int> prefixSum(n + 1, 0);
	for (int i = 0; i < n; i++) {
		prefixSum[i + 1] = prefixSum[i] + arr[i];
	}
	int res = INT_MIN;
	for (int i = k; i <= n; i++) {
		res = max(res, prefixSum[i] - prefixSum[i - k]);
	}
	
	cout << res;
}