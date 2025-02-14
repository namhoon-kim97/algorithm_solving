#include <bits/stdc++.h>
using namespace std;
int vis[2][500002];
int res[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	queue<int> q;
	q.push(n);
	vis[0][n] = 1;
	int plus = 1;
	bool flag = false;
	while (!q.empty()) {
		k += plus;
		if (k > 500000) break;
		if (vis[plus % 2][k]) {
			flag = true;
			break;
		}
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			auto cur = q.front(); q.pop();
			vector<int> temp = { cur - 1, cur + 1, cur * 2 };
			for (auto nx : temp) {
				if (nx < 0 || nx > 500000) continue;
				if (vis[plus % 2][nx]) continue;
				vis[plus % 2][nx] = vis[(plus + 1) % 2][cur] + 1;
				if (nx == k) {
					flag = true;
					break;
				}
				q.push(nx);
			}
			if (flag) break;
		}
		if (flag) break;
		plus++;
	}
	if (flag)
		cout << plus << '\n';
	else
		cout << -1;
}