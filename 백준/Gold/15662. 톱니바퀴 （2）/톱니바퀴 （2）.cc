#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& wheel, int dir) {
	vector<int> temp = wheel;
	if (dir == 1) {
		for (int i = 0; i < 8; i++) {
			wheel[i] = temp[(i + 7) % 8];
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			wheel[i] = temp[(i + 1) % 8];
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	vector<vector<int>> wheels;
	for (int i = 0; i < t; i++) {
		string temp;
		cin >> temp;
		vector<int> temp2;
		for (int j = 0; j < 8; j++) {
			temp2.push_back(temp[j] - '0');
		}
		wheels.push_back(temp2); // idx 오른쪽 2번, 왼쪽 6번
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		// a기준 왼쪽
		a--;
		int leftA = a - 1;
		int prevLeft = a;
		int leftB = b * -1;
		vector<int> rotateDir(t, 0);
		rotateDir[a] = b;
		while (leftA >= 0) {
			if (wheels[prevLeft][6] != wheels[leftA][2])
				rotateDir[leftA] = leftB;
			else break;
			prevLeft = leftA;
			leftA--;
			leftB *= -1;
		}
		int rightA = a + 1;
		int prevRight = a;
		int rightB = b * -1;
		// a기준 오른쪽
		while (rightA < t) {
			if (wheels[prevRight][2] != wheels[rightA][6])
				rotateDir[rightA] = rightB;
			else break;
			prevRight = rightA;
			rightA++;
			rightB *= -1;
		}
		for (int i = 0; i < t; i++) {
			if (rotateDir[i] != 0)
				rotate(wheels[i], rotateDir[i]);
		}
	}
	int res = 0;
	for (auto a : wheels) {
		if (a[0] == 1) res++;
	}
	cout << res;
}