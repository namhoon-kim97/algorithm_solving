#include <bits/stdc++.h>

using namespace std;

vector<int> arr[32001];
int cnt[32001];
vector<int> res;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		cnt[b]++;
	}
	
	queue<int> q;
	for (int i = 1; i <= n; i++) if (cnt[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		res.push_back(cur);
		for (int num : arr[cur]) {
			cnt[num]--;
			if (cnt[num] == 0) q.push(num);
		}
	}

	for (int ans : res) cout << ans << " ";

}
