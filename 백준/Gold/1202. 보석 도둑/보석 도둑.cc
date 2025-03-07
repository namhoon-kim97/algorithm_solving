#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<long long, long long>> jems;
	for (int i = 0; i < n; i++) {
		long long m, v;
		cin >> m >> v;
		
		jems.push_back({ m,v });
	}
	vector<int> bags;
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bags.push_back(c);
	}
	sort(jems.begin(), jems.end());
	sort(bags.begin(), bags.end());

	long long res = 0;
	priority_queue<long long> pq;
	
	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && jems[j].first <= bags[i]) pq.push(jems[j++].second);
		if (pq.size()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res;
}