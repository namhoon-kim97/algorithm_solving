#include <bits/stdc++.h>

using namespace std;
int arr[7];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> arr[i];

	int t, p;
	cin >> t >> p;

	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		cnt += (arr[i] / t);
		if (arr[i] % t > 0)
			cnt++;
	}

	cout << cnt << '\n';
	cout << n / p << ' ' << n - n / p * p;
}