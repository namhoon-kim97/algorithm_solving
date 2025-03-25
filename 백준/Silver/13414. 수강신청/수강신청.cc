#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int k, l;
	cin >> k >> l;

	unordered_map<string, int> um;
	for (int i = 0; i < l; i++) {
		string x;
		cin >> x;
		um[x] = i;
	}

	priority_queue<pair<int, string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
	for (auto cur : um) {
		pq.push({ cur.second, cur.first });
	}
	
	int cnt = 0;
	while (!pq.empty()) {
		cout << pq.top().second << '\n';
		pq.pop();
		cnt++;
		if (cnt == k) break;
	}
}