#include <bits/stdc++.h>
using namespace std;
int arr[100001];
bool vis[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	long long cnt = 0;
	int l = 0;
	for (int r = 0; r < n; r++) {
		while (vis[arr[r]]) {
			vis[arr[l]] = false;
			l++;
		}
		vis[arr[r]] = true;
		cnt += (r - l + 1);
	}

	
	cout << cnt;
}