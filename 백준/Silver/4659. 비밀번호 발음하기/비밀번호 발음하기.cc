#include <bits/stdc++.h>
using namespace std;
//string v[5] = {"a", "e", "i","o", "u"};
char v[5] = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char inputA) {
	for (auto a : v)
		if (a == inputA)return true;
	return false;
}

bool solution(string input) {
	bool flag = false;
	for (auto a : v) {
		if (input.find(a) != string::npos) {
			flag = true;
			break;
		}
	}
	if (!flag) return false;

	int continuousCnt = 0;
	for (int i = 0; i < input.size() - 1; i++) {
		if (isVowel(input[i]) && isVowel(input[i + 1]))
			continuousCnt++;
		else if (!isVowel(input[i]) && !isVowel(input[i + 1]))
			continuousCnt++;
		else continuousCnt = 0;

		if (continuousCnt == 2) return false;
		if (input[i] == input[i + 1] && !(input[i] == 'e' || input[i] == 'o')) return false;
	}
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string temp;
		cin >> temp;
		if (temp == "end") break;
		if (solution(temp))
			cout << "<" << temp << ">" << " is acceptable." << '\n';
		else 
			cout << "<" << temp << ">" << " is not acceptable." << '\n';
	}
}