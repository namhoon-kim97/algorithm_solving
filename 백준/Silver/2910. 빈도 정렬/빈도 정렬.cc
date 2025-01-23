#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int arr[1001];

struct CustomCompare {
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	map<pair<int,int>, int, CustomCompare> m;
	unordered_map<int, int> um;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		um[arr[i]]++;
	
	}
	for (int i = 0; i < n; i++) {
		m.insert({ { arr[i], um[arr[i]] }, n - i });
	}

	vector<pair<pair<int, int>, int>> vec(m.begin(), m.end());
	std::sort(vec.begin(), vec.end(),
		[](const pair<pair<int, int>, int >& a, const pair<pair<int, int>, int >& b) {
			if (a.first.second == b.first.second) {
				return a.second > b.second;
			}
			return a.first.second > b.first.second;
		});


	for (auto& a : vec) {
		while (um[a.first.first] != 0) {
			cout << a.first.first << ' ';
			um[a.first.first]--;
		}
	}


}