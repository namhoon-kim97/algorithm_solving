#include <bits/stdc++.h>

using namespace std;

int solution(int a) {
	int i = 0;
	int n = 0;
	while (true) {
		i += 1;
		n = (n * 10 + 1) % a;
		if (n == 0)
			return i;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;
	while (cin >> a) {
		cout << solution(a) << '\n';
	}
}