#include <bits/stdc++.h>
using namespace std;

bool compare(string& a, string& b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> res;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		string temp = "";
		for (int j = 0; j < input.size(); j++) {
			if (isdigit(input[j])) {
				temp += input[j];
			}
			else {
				if (temp != "") {
					if (temp[0] == '0') {
						int zidx = temp.find_first_not_of('0');
						if (zidx >= temp.size())
							temp = "0";
						else
							temp = temp.substr(zidx);
					}
					res.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp != "") {
			if (temp[0] == '0') {
				if (temp.size() != 1) {
					int zidx = temp.find_first_not_of('0');
					if (zidx >= temp.size())
						temp = "0";
					else
						temp = temp.substr(zidx);
				}
			}
			res.push_back(temp);
		}
	}
	sort(res.begin(), res.end(), compare);
	for (auto a : res)
		cout << a << '\n';
}