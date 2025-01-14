#include <bits/stdc++.h> 
using namespace std;

map<char, int> firstName;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		firstName[temp[0]]++;
	}
	bool flag = false;
	for (auto a : firstName) {
		if (a.second >= 5) {
			cout << a.first;
			flag = true;
		}
	}
	if (!flag)
		cout << "PREDAJA";
}