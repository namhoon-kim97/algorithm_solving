#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
long long dp[100001];
int n;

struct Line {
	long long m, c; // y = mx + c
	
	//교점 x좌표
	double intersectX(const Line& other) const {
		return (double)(other.c - c) / (m - other.m);
	}

	//y 값
	long long get(long long x) const {
		return m * x + c;
	}
};

deque<Line> cht;
long long query(long long x) {
	while (cht.size() >= 2 && cht[0].get(x) >= cht[1].get(x))
		cht.pop_front();
	return cht.front().get(x);
}

void addLine(long long m, long long c) {
	Line newLine = { m,c };
	while (cht.size() >= 2) {
		Line l1 = cht[cht.size() - 2];
		Line l2 = cht[cht.size() - 1];
		if (l1.intersectX(l2) >= l2.intersectX(newLine)) {
			cht.pop_back();
		}
		else break;
	}
	cht.push_back(newLine);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	//dp[i] = min(dp[j] + b[j] * a[i]);
	dp[1] = 0;
	addLine(b[0], dp[1]);
	for (int i = 2; i <= n; i++) {
		dp[i] = query(a[i - 1]);
		addLine(b[i - 1], dp[i]);
	}
	cout << dp[n];
}