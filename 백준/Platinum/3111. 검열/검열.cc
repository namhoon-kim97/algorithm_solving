#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string A, T;
	cin >> A;
	cin >> T;
	int T_size = T.size();
	int A_size = A.size();

	int st = 0;
	int en = T_size - 1;

	while (true) {
		bool flag = 0;
		for (int i = st; i < T_size; i++) {
			if (T.substr(i, A_size) == A) {
				T.erase(i, A_size);
				T_size = T.size();
				(i - 2 * A_size) <= 0 ? st = 0 : st = i - (2 * A_size);
				flag = 1;
				break;
			}
		}

		if (!flag) { break; }
		flag = 0;
		en = min(en, (int)T.size() - 1);

		for (int j = en; j >= 0; j--) {
			if (T.substr(j, A_size) == A) {
				T.erase(j, A_size);
				T_size = T.size();
				en = j;
				flag = 1;
				break;
			}
		}
		if (!flag) { break; }
	}
	cout << T;
	return 0;
}