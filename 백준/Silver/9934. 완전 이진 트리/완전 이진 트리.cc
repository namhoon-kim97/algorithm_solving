#include <bits/stdc++.h>
using namespace std;
int k;
int arr[1025];
vector<int> ans[11];
void solution(int st, int en, int depth) {
	if (depth == k)
		return;
	int mid = (st + en) / 2;
	ans[depth].push_back(arr[mid]);
	solution(st, mid - 1, depth + 1);
	solution(mid + 1, en, depth + 1);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	
	cin >> k;
	int len = (1 << k) - 1;
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	solution(0, len, 0);
	for (auto a : ans) {
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
}