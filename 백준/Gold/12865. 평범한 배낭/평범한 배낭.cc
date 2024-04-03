#include <bits/stdc++.h>

using namespace std;

int d[100001];
int w[100001];
int v[1001];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	
	for (int i = 1; i <= n; i++) {
		for (int j = k; j > 0; j--) {
			if (w[i] <= j) d[j] = max(d[j], d[j - w[i]] + v[i]);
		}
	}

	cout << d[k];

}