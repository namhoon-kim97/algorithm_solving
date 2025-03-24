#include <bits/stdc++.h>

using namespace std;
int vis[100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		int p, q;
		cin >> p >> q;
		pq.push({ p,q }); // 시작시간 빠른순으로 정렬
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> users; // 끝나는시간, 이용자리;
	priority_queue<int, vector<int>, greater<int>> emptySeats;

	int curTime = 0;
	int res = 0;

	int idx = 1;
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		bool flag = false;
		while (!users.empty() && users.top().first <= cur.first) {
			emptySeats.push(users.top().second);
			users.pop();
		}
		if (!emptySeats.empty()) {
			int seat = emptySeats.top(); emptySeats.pop();
			vis[seat]++;
			users.push({ cur.second, seat });
		}
		else {
			vis[idx]++;
			users.push({ cur.second, idx++ }); // 사용 인원들, 끝나는 시간 빠른 순으로 정렬
		}
		res = max(res, (int)users.size());
	}
	cout << res << '\n';
	for (int i = 1; i <= res; i++)
		cout << vis[i] << ' ';
}