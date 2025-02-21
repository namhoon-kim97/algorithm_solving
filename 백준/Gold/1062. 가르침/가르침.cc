#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> arr;
const string essential = "antic";
set<char> learned;
int maxReadable = 0;

int countWords(set<char>& learned) {
	int cnt = 0;
	for (auto& word : arr) {
		bool readable = true;
		for (auto& ch : word) {
			if (learned.find(ch) == learned.end()) {
				readable = false;
				break;
			}
		}
		if (readable) cnt++;
	}
	return cnt;
}

void dfs(int idx, int cnt) {
	if (cnt == k - 5) {
		maxReadable = max(maxReadable, countWords(learned));
		return;
	}

	for (int i = idx; i < 26; i++) {
		char ch = 'a' + i;
		if (essential.find(ch) == string::npos && learned.find(ch) == learned.end()) {
			learned.insert(ch);
			dfs(i + 1, cnt + 1);
			learned.erase(ch);
		}
	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s = s.substr(4, s.size() - 4 - 4);
		set<char> uniqueChars;
		for (char ch : s) {
			if (essential.find(ch) == string::npos) {
				uniqueChars.insert(ch);
			}
		}
		arr[i] = string(uniqueChars.begin(), uniqueChars.end());
	}

	if (k < 5) {
		cout << 0;
		return 0;
	}

	
	for (char ch : essential) {
		learned.insert(ch);
	}


	dfs(0, 0);
	cout << maxReadable << endl;
}