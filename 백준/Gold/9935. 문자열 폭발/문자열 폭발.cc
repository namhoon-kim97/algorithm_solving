#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string inputString;
	cin >> inputString;
	string bomb;
	cin >> bomb;

	//stack<char> temp;
	string temp = "";
	int bombLength = bomb.length();
	for (int i = 0; i < inputString.length(); i++) {
		temp += inputString[i];
		int tempLength = temp.length();
		if (tempLength >= bombLength && temp.substr(tempLength - bombLength) == bomb) {
			temp.resize(tempLength - bombLength);
		}
	}
	if (temp == "")
		cout << "FRULA";
	else cout << temp;
}