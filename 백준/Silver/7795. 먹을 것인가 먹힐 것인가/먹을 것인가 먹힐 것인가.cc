#include <bits/stdc++.h>
using namespace std;
int arr[20001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			sum += ((arr + n) - upper_bound(arr, arr + n, x) );
		}
		cout << sum << '\n';
	}

}