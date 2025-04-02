#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);


	int t;
	cin >> t;
	int cur = 1;
	while (t--) {
		vector<int> plates;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			plates.push_back(temp);
		}
	
		
		int cnt = *max_element(plates.begin(), plates.end());
		for (int target = 1; target < cnt; target++) {
			int special = 0;
			for (int p : plates) {
				special += (p - 1) / target;
			}
			cnt = min(cnt, special + target);
		}
		
		cout << "Case #" << cur << ": " << cnt << '\n';
		cur++;
	}
}