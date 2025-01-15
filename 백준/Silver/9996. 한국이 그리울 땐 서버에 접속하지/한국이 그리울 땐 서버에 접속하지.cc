#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, string d) {
	int st = 0;
	auto en = s.find(d);
	vector<string> ret;
	while (en != string::npos) {
		string temp = s.substr(st, en - st);
		ret.push_back(temp);
		st = en + d.size();
		en = s.find(d, st);
	}
	ret.push_back(s.substr(st));
	return ret;
}

bool startsWith(const std::string& str, const std::string& prefix) {
	if (str.size() < prefix.size()) {
		return false;
	}
	return str.substr(0, prefix.size()) == prefix;
}

bool endWith(const std::string& str, const std::string& suffix) {
	if (str.size() < suffix.size()) {
		return false;
	}
	return str.substr(str.size() - suffix.size()) == suffix;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string pattern;
	cin >> pattern;
	vector<string> arr;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}
	vector<string> splitPattern = split(pattern, "*");
	if (splitPattern.size() != 2) {
		cout << "NE" << '\n';
		return 0;
	}
	for (auto a : arr) {
		if (startsWith(a, splitPattern[0]) && a.size() >= splitPattern[0].size() + splitPattern[1].size()) {
			if (endWith(a, splitPattern[1])) {
				cout << "DA" << '\n';
				continue;
			}
		}
		cout << "NE" << '\n';
	}
}