#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int m;
	cin >> m;
	int s = 0;
	for (int i = 0; i < m; i++) {
		string op;
		int num;
		cin >> op;
		if (op == "add") {
			cin >> num;
			s |= (1 << num);
		}
		else if (op == "remove") {
			cin >> num;
			s &= ~(1 << num);
		}
		else if (op == "check") {
			cin >> num;
			cout << ((s & (1 << num)) ? 1 : 0) << '\n';
		}
		else if (op == "toggle") {
			cin >> num;
			s ^= (1 << num);
		}
		else if (op == "all") {
			s = (1 << 21) - 1;	
		}
		else if (op == "empty") {
			s = 0;
		}
	}
}