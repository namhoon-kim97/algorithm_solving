#include <bits/stdc++.h>

using namespace std;
int arr[15001];
int vis[15001];
int m,n;

bool findNum(int cur, int st) {
	int target = m - cur;
	int en = n - 1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (arr[mid] < target)
			st = mid + 1;
		else if (arr[mid] > target)
			en = mid - 1;
		else
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;	

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (findNum(arr[i], i + 1)) {
			cnt++;
		}
	}
	cout << cnt;
}