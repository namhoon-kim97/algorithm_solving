#include <bits/stdc++.h>
using namespace std;
int arr[21][21];
bool vis[21];
int res = INT_MAX;
int n;

void solution(int cnt, int idx) {
	if (cnt == (n / 2) - 1) {
		int startSum = 0;
		int linkSum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (vis[i] && vis[j]) startSum += arr[i][j];
				else if (!(vis[i] || vis[j])) linkSum += arr[i][j];
			}
		}

		res = min(res, abs(startSum - linkSum));
		return;
	}
	for (int i = idx; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			solution(cnt + 1, i + 1);
			vis[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	vis[1] = true;
	solution(0,2);
	cout << res;
}