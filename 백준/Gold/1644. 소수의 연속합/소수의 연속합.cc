#include <bits/stdc++.h>

using namespace std;
bool arr[4000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	arr[0] = true;
	arr[1] = true;
	for (int i = 2; i * i <= n; i++) {
		if (arr[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			arr[j] = true;
		}
	}
	vector<int> primes;
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) primes.push_back(i);
	}
	int l = 0;
	int r = 0;
	int sum = 0;
	int cnt = 0;
	
	while (r < primes.size()) {
		if (sum < n) {
			sum += primes[r++];
		}
		else if (sum > n)
			sum -= primes[l++];
		else {
			cnt++;
			sum -= primes[l++];
		}
	}
	if (!arr[n]) cnt++;
	cout << cnt;
}