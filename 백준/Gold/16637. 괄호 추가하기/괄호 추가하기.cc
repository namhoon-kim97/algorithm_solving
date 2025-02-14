#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> op;
int res = INT_MIN;
int operation(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
}

void solution(int cur, int cnt) {
	if (cnt == num.size() - 1) {
		res = max(res, cur);
		return;
	}
	solution(operation(cur, num[cnt + 1], op[cnt]), cnt + 1);
	if (cnt + 1 < op.size()) {
		int temp = operation(num[cnt + 1], num[cnt + 2], op[cnt + 1]);
		solution(operation(cur ,temp, op[cnt]), cnt + 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		if (i % 2 == 0) 
			num.push_back(temp - '0');
		else op.push_back(temp);
	}

	solution(num[0], 0);
	cout << res;
}