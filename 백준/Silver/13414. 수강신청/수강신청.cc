#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int k, l;
	cin >> k >> l;
	set<string> ans;
	unordered_map<int, string> um;
	unordered_map<string, int> um2;
	for (int i = 0; i < l; i++) {
		string x;
		cin >> x;
		
		if (ans.count(x)) {
			um[um2[x]] = "-1";
		}
		um2[x] = i+1;
		um[um2[x]] = x;
		ans.insert(x);
	}
	
	int cnt = 0;
	for (int i = 1; i <= l; i++) {
		if (um[i] != "-1") {
			cout << um[i] << '\n';
			cnt++;
		}
		if (cnt == k) break;
	}
}