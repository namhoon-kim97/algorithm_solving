#include <bits/stdc++.h>
using namespace std;

vector<int> timeTable(100001, -1);
vector<int> cnt(100001, 0);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);

	timeTable[n] = 0;
	cnt[n] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		vector<int> temp = { cur + 1, cur - 1, cur * 2 };
		for (auto nxt : temp) {
			if (nxt >= 0 && nxt <= 100000) {
				if (timeTable[nxt] == -1) {
					timeTable[nxt] = timeTable[cur] + 1;
					cnt[nxt] = cnt[cur];
					q.push(nxt);
				}
				else if (timeTable[nxt] == timeTable[cur] + 1) {
					cnt[nxt] += cnt[cur];
				}
			}
		}
	}
	cout << timeTable[k] << '\n' << cnt[k];
}