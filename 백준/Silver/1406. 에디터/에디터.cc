#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string x;
	cin >> x;

	list<char> ans(x.begin(), x.end());	
	auto cursor = ans.end();

	int n;
	cin >> n;

	while (n--) {
		char input;
		cin >> input;
		if (input == 'P') {
			char temp;
			cin >> temp;
			ans.insert(cursor, temp);
		}
		else if (input == 'L'){
			if (cursor != ans.begin()) cursor--;
		}
		else if (input == 'D'){
			if (cursor != ans.end()) cursor++;
		}
		else if (input == 'B'){
			if (cursor != ans.begin()) {
				cursor--;
				cursor = ans.erase(cursor);
			}
		}
	}

	for (auto x : ans)
		cout << x;
}