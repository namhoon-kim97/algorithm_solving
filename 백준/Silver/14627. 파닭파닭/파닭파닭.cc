#include <bits/stdc++.h>
using namespace std;
long long res;
int s, c;
vector<int> arr;

bool solution(int x) {
	long long sum = 0;
	long long remain = 0;

	for (int i = 0; i < arr.size(); i++) {
		int cur = arr[i] / x;
		if (c - sum < cur)
			cur = c - sum;
		sum += cur;
		remain += (arr[i] - (x * cur));
	}

	if (sum >= c)
		res = remain;
	return sum < c; // 파닭 못 만들면 줄여야함.
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	int st = 1;
	int en = 1e9;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (solution(mid))
			en = mid - 1;
		else st = mid + 1;
	}
	cout << res;
}