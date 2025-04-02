#include <bits/stdc++.h>
using namespace std;
long long res;
long long n,m;
vector<long long> arr;

long long solution(long long x) {
	long long cnt = m;
	for (int i = 0; i < m; i++)
		cnt += (x / arr[i]);
	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		long long temp;
		cin >> temp;
		arr.push_back(temp);
	}
	if (n <= m) {
		cout << n << '\n';
		return 0;
	}


	long long st = 0;
	long long en = 6e10;
	long long answerTime = 0;
	while (st <= en) {
		long long mid = (st + en) / 2;
		if (solution(mid) >= n) { // mid시간까지 놀이기구 탑승한 아이가 n명 이상이면 가능
			en = mid - 1;
			answerTime = mid;
		}
		else st = mid + 1;
	}
	
	long long cntBefore = solution(answerTime - 1);
	for (int i = 0; i < m; i++) {
		if (answerTime % arr[i] == 0) {
			cntBefore++;
			if (cntBefore == n) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
}