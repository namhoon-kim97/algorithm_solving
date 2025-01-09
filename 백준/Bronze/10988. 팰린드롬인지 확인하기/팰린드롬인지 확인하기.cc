#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string temp;
	cin >> temp;
	int st = 0;
	int en = temp.size() - 1;
	while (st <= en) {
		if (temp[st] == temp[en]) {
			st++;
			en--;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	cout << 1;

}