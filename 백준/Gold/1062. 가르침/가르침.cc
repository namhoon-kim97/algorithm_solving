#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> words;
int res, alphaMask;
bool vis[26];
void dfs(int idx, int cnt, int mask) {
	if (cnt == (k - 5)) {
		// 판별
		int cntW = 0;
		for (auto a : words) {
			if ((a & mask) == a) cntW++;
		}
		res = max(res, cntW);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if ((mask & (1 << i)) == 0) {
			dfs(i + 1, cnt + 1, mask | (1 << i	));
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		int wordMask = 0;
		for (char c : temp) {
			wordMask |= (1 << (c - 'a'));
		}
		
		words.push_back(wordMask);
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}

	alphaMask |= (1 << ('a' - 'a'));
	alphaMask |= (1 << ('n' - 'a'));
	alphaMask |= (1 << ('t' - 'a'));
	alphaMask |= (1 << ('i' - 'a'));
	alphaMask |= (1 << ('c' - 'a'));

	dfs(0, 0, alphaMask);
	cout << res;
}