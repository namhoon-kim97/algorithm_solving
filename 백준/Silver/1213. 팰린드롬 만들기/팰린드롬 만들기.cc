#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	string name;

	cin >> name;
	map<char, int> charCount;

	for (char c : name) {
		charCount[c]++;
	}

	int oddCnt = 0;
	char oddChar = '\0';
	for (auto a : charCount) {
		if (a.second % 2 != 0) {
			oddCnt++;
			oddChar = a.first;
		}
	}

	if (oddCnt > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	string half = "";
	for (auto a : charCount) {
		half += string(a.second / 2, a.first);
	}
	
	string result = half;
	if (oddCnt == 1) {
		result += oddChar;
	}
	reverse(half.begin(), half.end());
	result += half;
	cout << result;
}
