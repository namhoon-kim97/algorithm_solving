#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, m;
	cin >> h >> m;

	int curTime = h * 60 + m;
	curTime -= 45;
	int hour = curTime / 60;
	int minute = curTime - hour * 60;
	if (minute < 0) {
		hour = 23;
		minute = 60 + minute;
	}
	cout << hour << ' ' << minute;
}