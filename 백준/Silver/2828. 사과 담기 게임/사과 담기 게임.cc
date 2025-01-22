#include <bits/stdc++.h>
using namespace std;
int arr[21];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int j;
	cin >> j;
	for (int i = 0; i < j; i++)
		cin >> arr[i];
	int ans = 0;
	int st = 0;
	int en = m - 1;
	if (m - 1 < arr[0]) { 
		ans = arr[0] - (m - 1);
		st = arr[0] - m + 1;
		en = arr[0];
	}
	for (int i = 1; i < j; i++) {
		if (arr[i] >= st && arr[i] <= en) continue;
		if (arr[i] > en) {  // 사과가 오른쪽 범위 밖에 있을 때
			ans += arr[i] - en;
			st = arr[i] - m + 1;
			en = arr[i];
		}
		else if (arr[i] < st) {  // 사과가 왼쪽 범위 밖에 있을 때
			ans += st - arr[i];
			st = arr[i];
			en = arr[i] + m - 1;
		}
		else continue;
	}
	cout << ans - 1;
}