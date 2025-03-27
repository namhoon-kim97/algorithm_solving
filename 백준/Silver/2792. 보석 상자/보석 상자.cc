#include <bits/stdc++.h>
using namespace std;
int arr[300001];
int n, m;

bool solution(int x) {
	if (x == 0)return false;
	int cnt = 0;
	for (int i = m - 1; i >= 0; i--) {
		cnt += (arr[i] / x);
		if (arr[i] % x != 0) cnt++;
	}
	return cnt <= n;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);


	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	// 질투심이 x일 때 학생들에게 나누어 줄 수 있는가?
	
	int st = 0;
	int en = 1000000001;
	int ans = en;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (solution(mid)) {
			en = mid - 1;
			ans = mid;
		}
		else st = mid + 1;
	}
	cout << ans;
}