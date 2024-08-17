#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int d[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	if (k >= n) {
		cout << 0;
		return 0;
	}

	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {
		d[i] = arr[i + 1] - arr[i];
	}

	sort(d, d + n - 1);

	int ans = 0;
	for (int i = 0; i < n - k; i++)
		ans += d[i];
	cout << ans;
}