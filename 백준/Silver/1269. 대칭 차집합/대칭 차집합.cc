#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int na, nb;
	cin >> na >> nb;

	vector<int> ta;
	vector<int> tb;
	unordered_map<int, int> a;
	unordered_map<int, int> b;
	for (int i = 0 ; i < na; i++){
		int temp;
		cin >> temp;
		a[temp] = 1;
		ta.push_back(temp);
	}
	for (int i = 0; i < nb; i++){
		int temp;
		cin >> temp;
		b[temp] = 1;
		tb.push_back(temp);
	}

	int cnt = 0;
	for (int i = 0; i < na; i++) {
		if (b[ta[i]])
			cnt++;
	}
	int first = na - cnt;

	cnt = 0;
	for (int i = 0; i < nb; i++) {
		if (a[tb[i]])
			cnt++;
	}
	int second = nb - cnt;
	cout << first + second;
}