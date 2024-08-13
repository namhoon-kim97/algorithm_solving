#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int d[100005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	
	d[0] = arr[0];
	int maxValue = arr[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + arr[i], arr[i]);
		maxValue = max(d[i], maxValue);
	}
	cout << maxValue;
}
