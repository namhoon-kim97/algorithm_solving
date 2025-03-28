#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int arr2[100001];

int n, m;

bool solution(int x) {
	if (x == 0)return false;
	int cnt = 1;
	int temp = x;
	for (int i = 0; i < n; i++) {
		if (arr[i] > x) return false;
		if (temp < arr[i]) {
			temp = x;
			cnt++;
		}
		temp -= arr[i];
	}
	return cnt <= m;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	int st = 0;
	int en = 10000000001;
	int ans = en;
	while (st < en) {
		int mid = (st + en) / 2;
		if (solution(mid)) {
			en = mid;
			ans = mid;
		}
		else st = mid + 1;
	}
	cout << ans;

}