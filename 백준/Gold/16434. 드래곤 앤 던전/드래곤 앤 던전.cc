#include <bits/stdc++.h>
using namespace std;
int n, m;
long long arr[123456][3];

bool solution(long long maxHP) {
	long long atk = m;
	long long curHP = maxHP;

	for (int i = 0; i < n; i++) {
		if (arr[i][0] == 1) {
			long long monsterTurn = (arr[i][2] + atk - 1) / atk;
			long long damage = (monsterTurn - 1) * arr[i][1];
			curHP -= damage;
			if (curHP <= 0) return false;
		}
		else {
			atk += arr[i][1];
			curHP = min(maxHP,curHP + arr[i][2]);
		}
	}
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	long long st = 1;
	long long en = 1e18;
	long long ans = en;
	while (st < en) {
		long long mid = (st + en) / 2;
		if (solution(mid)) {
			en = mid;
			ans = mid;
		}
		else st = mid + 1;
	}
	cout << ans;
}