#include <bits/stdc++.h>

using namespace std;

struct Room {
	int baseLevel;
	vector<pair<string, int>> users;
};
vector<Room> rooms;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int p, m;
	cin >> p >> m;
	int idx = 0;
	for (int i = 0; i < p; i++) {
		int l;
		string n;
		cin >> l >> n;
		bool flag = true;
		for (auto& room : rooms) {
			if (room.users.size() < m && (l >= room.baseLevel - 10 && l <= room.baseLevel + 10)) {
				flag = false;
				room.users.push_back({ n,l });
				break;
			}
		}
		if (flag) { // 새로운 방을 만들어야 함
			Room newRoom;
			newRoom.baseLevel = l;
			newRoom.users.push_back({ n,l });
			rooms.push_back(newRoom);
		}
	}

	for (auto& room : rooms) {
		sort(room.users.begin(), room.users.end());
	}
	for (auto room : rooms) {
		if (room.users.size() == m)
			cout << "Started!\n";
		else cout << "Waiting!\n";
		for (auto a : room.users)
			cout << a.second << ' ' << a.first << '\n';
	}

}