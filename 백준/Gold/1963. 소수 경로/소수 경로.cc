#include <bits/stdc++.h>

using namespace std;
int arr[100001];
bool visited[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 2; i <= 100000; i++)
		arr[i] = i;

	for (int i = 2; i <= 100000; i++) {
		if (arr[i] == 0) continue;

		for (int j = 2 * i; j <= 100000; j += i) {
			arr[j] = 0;
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int cnt = 0;
		int n, m;
		cin >> n >> m;

		fill(visited, visited + 100001, false);
		queue<pair<int,int>> q;
		q.push({ n ,0 });
		visited[n] = true;

		bool flag = false;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			if (cur.first == m) {
				cout << cur.second << '\n';
				flag = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				// 각 자리 하나씩 더해서 소수면 q에 넣는다.
				string temp = to_string(cur.first);
				for (char c = '0'; c <= '9'; c++) {
					if (i == 0 && c == '0') continue;
					if (temp[i] == c) continue;
					temp[i] = c;
					int new_num = stoi(temp);

					if (arr[new_num] && !visited[new_num]) {
						q.push({ new_num , cur.second + 1 });
						visited[new_num] = true;
					}
				}
			}
		}
		if (!flag)
			cout << "Impossible" << '\n';
	}

}