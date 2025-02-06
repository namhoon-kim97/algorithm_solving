#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
int n, m;
int res = INT_MAX;

vector<pair<int, int>> houses;
vector<pair<int, int>> stores;
vector<pair<int, int>> store_temp;

void go(int cnt) {
	if (store_temp.size() == m) {
		// 고른 집들 기준으로 치킨 거리 구하고
		// res 갱신
		int chicken_distance = 0;
		for (int i = 0; i < houses.size(); i++) {
			int min_ck_dis = INT_MAX;
			for (int j = 0; j < store_temp.size(); j++) {
				min_ck_dis = min((abs(houses[i].first - store_temp[j].first) + abs(houses[i].second - store_temp[j].second)), min_ck_dis);
			}
			chicken_distance += min_ck_dis;
		}
		res = min(res, chicken_distance);
	}

	for (int i = cnt; i < stores.size(); i++) {
		store_temp.push_back(stores[i]);
		go(i + 1);
		store_temp.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				houses.push_back({ i,j });
			if (arr[i][j] == 2)
				stores.push_back({ i,j });
		}
	}
	go(0);
	cout << res;
}