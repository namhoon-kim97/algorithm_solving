#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int x;
	cin >> x;

	sort(arr, arr + n);
	int st = 0;
	int en = n - 1;
	int cnt = 0;
	while (st < en) {
		if (arr[st] + arr[en] == x) {
			cnt++;
			en--;
		}
		else if (arr[st] + arr[en] < x)
			st++;
		else
			en--;
	}
	cout << cnt;
	
}