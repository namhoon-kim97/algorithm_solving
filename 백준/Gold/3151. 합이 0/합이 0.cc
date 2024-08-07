#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	sort(arr, arr + n);
	
	long long ans = 0;
	for (int i = 0; i < n - 2; i++) {
		int st = i + 1;
		int en = n - 1;
		int cnt = 0;

		while (st < en) {
			if (arr[i] + arr[st] + arr[en] == 0) {
				if (arr[st] == arr[en]) {
					ans += (en - st);
					cnt = 0;
				}
				else {
					if (cnt == 0) {
						int idx = en;
						while (idx > st && arr[i] + arr[st] + arr[idx--] == 0)
							cnt++;
					}
					ans += cnt;
				}
				st++;
			}
			else if (arr[i] + arr[st] + arr[en] < 0) {
				st++;
				cnt = 0;
			}
			else {
				en--;
				cnt = 0;
			}
		}
	}
	cout << ans;
	
}