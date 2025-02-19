#include <bits/stdc++.h>
using namespace std;
int n, mp, mf, ms, mv;
int arr[16][6];
int res = INT_MAX;
vector<int> ans;
vector<vector<int>> result;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	
	for (int i = 0; i < (1 << n); i++) {
		vector<int> ans;
		int temp_mp = 0;
		int temp_mf = 0;
		int temp_ms = 0;
		int temp_mv = 0;
		int price = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				temp_mp += arr[j][0];
				temp_mf += arr[j][1];
				temp_ms += arr[j][2];
				temp_mv += arr[j][3];
				price += arr[j][4];
				ans.push_back(j + 1);
			}
		}
		
		if (temp_mp >= mp && temp_mf >= mf && temp_ms >= ms && temp_mv >= mv) {
			if (price < res) {
				res = price;
				result.clear();
				result.push_back(ans);
			}
			else if (price == res) {
				result.push_back(ans);
			}
		}
	}
	if (res == INT_MAX) {
		cout << -1;
		return 0;
	}
	sort(result.begin(), result.end());
	cout << res << '\n';
	for (auto a : result[0]) {
		cout << a << ' ';
	}
}