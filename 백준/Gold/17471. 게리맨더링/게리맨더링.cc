#include <bits/stdc++.h>
using namespace std;
vector<int> adj[11];
int arr[11];
int vis[11];
int comp[11];
int n;
int res = INT_MAX;
int sum;

int countBits(int x) {
	int cnt = 0;
	while (x) {
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

int solution(int num, int flag) {
	queue<int>q;
	q.push(num);
	vis[num] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			if (!vis[nxt] && comp[nxt] == flag) {
				vis[nxt] = 1;
				q.push(nxt);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++) {
		fill(vis, vis + n + 1, 0);
		fill(comp, comp + n + 1, 0);
		int start1 = -1, start2 = -1;
		int sum1 = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				comp[j + 1] = 1;
				sum1 += arr[j + 1];
				if (start1 == -1) start1 = j + 1;
			}
			else {
				if (start2 == -1) start2 = j + 1;
			}
		}

		if (solution(start1, 1) + solution(start2, 0) != n) continue;
		
		int sum2 = sum - sum1;
		res = min(res, abs(sum1 - sum2));
	}
	if (res == INT_MAX)
		cout << -1;
	else cout << res;
}	